// error:	OK
// langId:	21
// langName:	Haskell
// langVersion:	ghc-7.6.3
// time:	0
// date:	2013-08-22 01:41:25
// status:	0
// result:	0
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
import Data.Maybe
import Data.Char
import Data.List
import Data.String.Utils
import Control.Applicative

data Piece = King  | Queen | Rook | Bishop | Knight | Pawn deriving(Eq,Enum,Show)
data Actor = Black Piece | White Piece deriving(Eq)
type Field = Maybe Actor

newtype Board = Board [Field]

instance Show Actor where
    show (Black piece) = fmap toUpper $ show piece
    show (White piece) = fmap toLower $ show piece

instance Show Board where
    show (Board fields) = all $ split fields
        where
            all          = join "\n" . fmap rank . reverse
            rank         = join "\t" . fmap (maybe "." show)
            split []     = []
            split fields = let (r,o)=splitAt 8 fields in r:split o

fenPiece :: Char -> Maybe Piece
readFEN :: [Char] -> [Field]

fenPiece 'r' = Just Rook
fenPiece 'b' = Just Bishop
fenPiece 'n' = Just Knight
fenPiece 'q' = Just Queen
fenPiece 'k' = Just King
fenPiece 'p' = Just Pawn
fenPiece _   = Nothing

readFEN []             = []
readFEN ('/':nextrank) = readFEN nextrank
readFEN (piece:remain)
    | piece `elem` "rbnqkp"   = (White <$> fenPiece piece)            : readFEN remain
    | piece `elem` "RBNQKP"   = (Black <$> fenPiece (toLower piece))  : readFEN remain
    | piece `elem` ['1'..'8'] = (replicate (read [piece]) $ Nothing) ++ readFEN remain
    | otherwise = readFEN remain

main = do
   putStrLn.show.Board $ readFEN "4r3/pp4k1/7p/n1p1p1p1/NbPpP2n/1P1P1r2/P1QB4/R4RK1"

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif

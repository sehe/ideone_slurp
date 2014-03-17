// error:	OK
// langId:	21
// langName:	Haskell
// langVersion:	ghc-7.6.3
// time:	0
// date:	2013-08-22 02:11:16
// status:	0
// result:	15
// memory:	6292
// signal:	0
// public:	false
// ------------------------------------------------
import Data.Maybe
import Data.Char
import Data.List
import Control.Applicative

data Piece = King  | Queen | Rook | Bishop | Knight | Pawn deriving(Eq,Enum,Show)
data Actor = Black Piece | White Piece deriving(Eq)
type Field = Maybe Actor

newtype Board = Board [Field]

instance Show Actor where
    show (Black piece) = toUpper <$> show piece
    show (White piece) = toLower <$> show piece

instance Show Board where
    show (Board fields) = display $ split fields
        where
            display      = concat . intersperse "\n" . fmap rank . reverse
            rank         = concat . intersperse "\t" . fmap (maybe "." show)
            split []     = []
            split fields = let (r,o)=splitAt 8 fields in r:split o

fenPiece :: Char   -> Piece
readFEN  :: [Char] -> [Field]

fenPiece 'r' = Rook
fenPiece 'b' = Bishop
fenPiece 'n' = Knight
fenPiece 'q' = Queen
fenPiece 'k' = King
fenPiece 'p' = Pawn

readFEN (code:remain)
    | code `elem` "rbnqkp"   = (Just . White . fenPiece $ code)           : readFEN remain
    | code `elem` "RBNQKP"   = (Just . Black . fenPiece $ (toLower code)) : readFEN remain
    | code `elem` ['1'..'8'] = replicate (read [code]) Nothing ++ readFEN remain
    | code == '/' = readFEN remain
readFEN [] = []

main = do
   putStrLn . show . Board $ readFEN "4r3/pp4k1/7p/n1p1p1p1/NbPpP2n/1P1P1r2/P1QB4/R4RK1"

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout
ROOK	.	.	.	.	ROOK	KING	.
PAWN	.	QUEEN	BISHOP	.	.	.	.
.	PAWN	.	PAWN	.	rook	.	.
KNIGHT	bishop	PAWN	pawn	PAWN	.	.	knight
knight	.	pawn	.	pawn	.	pawn	.
.	.	.	.	.	.	.	pawn
pawn	pawn	.	.	.	.	king	.
.	.	.	.	rook	.	.	.

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo

#endif

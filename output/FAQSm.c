// error:	OK
// langId:	11
// langName:	C
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-03-31 17:25:59
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

struct track_ {
  char *tracks_title;
  int playlist_hits;
};
typedef struct track_ track;
 
struct album_ {
  int num_tracks;
  struct track_* tracks;
};
typedef struct album_ album;


const int max_number_of_album = 100;
int number_of_albums = 0;

album *all_albums_p = NULL;

void init_all_albums();
void done_all_albums();
album* append_album(int num_tracks);
void cleanup_album(album* a);

void init_all_albums()
{
    if (!all_albums_p)
        all_albums_p = (album *) malloc(sizeof(album)*max_number_of_album);
}

void done_all_albums()
{
    if (all_albums_p)
    {
        while (number_of_albums--)
            cleanup_album(&all_albums_p[number_of_albums]);

        free(all_albums_p);
        all_albums_p = NULL;
    }
}

album* append_album(int num_tracks)
{
    if (number_of_albums >= max_number_of_album)
        return NULL;

    int index = number_of_albums++;
    all_albums_p[index].num_tracks = num_tracks;
    all_albums_p[index].tracks     = (track*) malloc(sizeof(track)*num_tracks);

    return all_albums_p+index;
}

void cleanup_album(album* a)
{
    if (a)
    {
        while (a->num_tracks--)
            free_track(a->tracks[a->num_tracks]);

        free(a->tracks);
    }
}
 
// free_track left as an exercise for the reader

int main(int argc, const char *argv[])
{
    
    return 0;
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.c: In function ‘cleanup_album’:
prog.c:62: warning: implicit declaration of function ‘free_track’
/home/ch5tTB/cclmnAVV.o: In function `cleanup_album':
prog.c:(.text+0x43): undefined reference to `free_track'
collect2: ld returned 1 exit status

#endif

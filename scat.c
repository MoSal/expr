/* cat sparse files without the holes */


#define _FILE_OFFSET_BITS 64
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
	FILE* f;
	char *bytes;
	off_t track_data, track_hole, rd_size=1;
	size_t ret;

	if (argc != 2) return 1;

	f = fopen(argv[1],"rb");
	if (!f) return 2;

	while ((track_data = lseek(fileno(f), ftello(f), SEEK_DATA)) != -1) {
		if ((track_hole = lseek(fileno(f), ftello(f), SEEK_HOLE)) != -1) {
			if (track_hole > track_data) {
				rd_size = track_hole - track_data;
			}
		}
		fseeko(f, track_data, SEEK_SET);
		if ( (bytes = calloc(rd_size , sizeof(char))) == NULL  ) return 3;
		if ( (ret = fread(bytes, 1, rd_size, f)) != (size_t)rd_size && !feof(f) ) {
			return 4;
		}
		fwrite(bytes, 1, rd_size, stdout);
		free(bytes);
	}
	return 0;
}

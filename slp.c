#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define ERASE_AFTER "\033[0K"

int print_time(time_t t) {
	char t_str[1024];
	if ( !strftime(t_str, 1023, "%H:%M:%S", gmtime(&t)) ) {
		t_str[0]='\0';
	}
	fflush(stderr);
	fprintf(stderr, "Remaining: %s (%lu)%s\r", t_str, t, ERASE_AFTER);
	return 0;
}

int main( int argc , char **argv) {
	if (argc == 1) exit (1);
	time_t t, t_end;
	t_end = time(NULL) + atoi(argv[1]);
	while ( ( t = t_end - time(NULL) ) >= 0  ) {
		print_time(t);
		sleep(1);
	}
	print_time(0);
	fputc('\n', stderr);
	return 0;
}

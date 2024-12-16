#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>

int main(void) {
	mysql_library_init(0, NULL, NULL);
	MYSQL* conn = mysql_init(NULL);

	if (mysql_real_connect(conn, "127.0.0.1", "root", "", "routeplan", 0, NULL, NULL) == NULL) {
		fprintf(stderr, "connect error! %s\n", mysql_error(conn));
	} else {
		printf("Successfully connect to mysql!\n");
	}

	printf("Please enter your query: ");
	char* mysql_query = calloc(100, sizeof(char));
	fgets(mysql_query, 100, stdin);
	mysql_query[strlen(mysql_query) - 1] = '\0';



	mysql_close(conn);
	mysql_library_end();
	return EXIT_SUCCESS;
}

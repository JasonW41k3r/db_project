#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <windows.h>

int main(void) {
	mysql_library_init(0, NULL, NULL);
	MYSQL* conn = mysql_init(NULL);
	MYSQL_RES* res = NULL;
	MYSQL_ROW* row = NULL;
	char* host = calloc(20, sizeof(char));
	char* user = calloc(20, sizeof(char));
	char* passwd = calloc(50, sizeof(char));
	char* db = calloc(50, sizeof(char));
	int port = 0;
	printf("Host: ");
	gets(host);
	printf("Port: ");
	scanf("%d", &port);
	getchar();
	printf("Username: ");
	gets(user);
	printf("Password: ");
	gets(passwd);
	printf("Database: ");
	gets(db);
	

	if (mysql_real_connect(conn, host, user, passwd, db, port, NULL, NULL) == NULL) {
		fprintf(stderr, "connect error! %s\n", mysql_error(conn));
	} else {
		printf("Successfully connect to mysql!\n");
		Sleep(2000);
	}

	printf("Please enter your query: ");
	char* query = calloc(100, sizeof(char)); // The longest query limited to 100 chars
	fgets(query, 100, stdin);
	query[strlen(query) - 1] = '\0';

	if (mysql_query(conn, query)) {
		fprintf(stderr, "Error while executing query! %s\n", mysql_error(conn));
	}
	res = mysql_use_result(conn);
	while (row = mysql_fetch_row(res)) {
		for (int cnt = 0; cnt < mysql_num_fields(res); cnt++) {
			printf("%s\t", row[cnt] ? row[cnt] : "NULL");
		}
		printf("\n");
	}

	mysql_close(conn);
	mysql_library_end();
	return EXIT_SUCCESS;
}

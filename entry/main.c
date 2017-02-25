#include <stdio.h>
#include <string.h>
#include <unistd.h>

void init_bpool();
void init_hash();
void init_vector();
void init_front();

/*your can get file list by declaring this variable*/
Vector cmd_files;

static struct {
	char *short_opt;
	char *long_opt;
	char *value;
	bool onoff;
} registered_arguments[] = {
	/* add your options here.
	 * for example:
	 */
	[ArgumentPrintSyntaxTree] = {NULL, "print-syntax-tree"},
	[ArgumentPrintReduceStep] = {NULL, "print-reduce-step"},
};

bool get_onoff_from_arguments(int arg) {
	if(arg < sizeof(registered_arguments) / sizeof(registered_arguments[0])) {
		return registered_arguments[arg].onoff;
	}
	return false;
}

char *get_value_from_arguments(int arg) {
	if(arg < sizeof(registered_arguments) / sizeof(registered_arguments[0])) {
		return registered_arguments[arg].value;
	}
	return NULL;
}

char *dumps_argv(int argc, char *argv[]) {
	static char ret[1024];
	ret[0] = '[';
	for(int i = 1; i < argc; i++) {
		strcat(ret, "\"");
		strcat(ret, argv[i]);
		strcat(ret, "\"");
		if(i != argc - 1)
			strcat(ret, ",");
	}
	strcat(ret, "]");
	return ret;
}

void parse_arguments(int argc, char *argv[]) {
	logd("parse arguments={%d, %s}.\n", argc - 1, dumps_argv(argc, argv));
	vector_init(&cmd_files, sizeof(char *));
	for(int i = 1; i < argc; i++) {
		int match_state = 0;
		for(int j = 0; j < sizeof(registered_arguments) / sizeof(registered_arguments[0]); j++) {
			if(argv[i][0] == '-' && argv[i][1] == '-') {
				//long opt
				char *long_opt = registered_arguments[j].long_opt;
				if(!long_opt) continue;
				int len = strlen(long_opt);
				if(strncmp(&argv[i][2], long_opt, len) == 0) {
					match_state = 1;
					registered_arguments[j].onoff = true;
					if(long_opt[len - 1] == '=') {
						//fetch value
						registered_arguments[j].value = &argv[i][2 + len];
					}
				}
			}else if(argv[i][0] == '-') {
				//short opt
				char *short_opt = registered_arguments[j].short_opt;
				if(!short_opt) continue;
				if(argv[i][1] == short_opt[0]) {
					match_state = 1;
					registered_arguments[j].onoff = true;
					if(short_opt[1] == ':') {
						//fetch value
						if(i + 1 < argc)
							registered_arguments[j].value = argv[i + 1];
						else
							registered_arguments[j].value = NULL;
					}
				}
			}else{
				//files
				match_state = 2;
				vector_push(&cmd_files, argv[i]);
			}
		}

		if(match_state == 0) {
			fprintf(stderr, "Unknown Option '%s'.\n", argv[i]);
		}
	}
}

int main(int argc, char *argv[])
{
	/*dont't move it*/
	parse_arguments(argc, argv);

	/*init bpool module*/
	init_bpool();

	/*init hash module*/
	init_hash();

	/*init hash module*/
	init_vector();

	/*int front module*/
	init_front();

	/*init your own module*/

	logd("normal exit.\n");
    return 0;
}

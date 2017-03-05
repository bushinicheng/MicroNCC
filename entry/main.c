#include <stdio.h>
#include <string.h>
#include <unistd.h>

void init_bpool();
void init_hash();
void init_vector();
void init_front();

/*you can get file list by declaring this variable*/
vec_t cmd_files;

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

	/*----------*/
	[ArgumentHelp] = {"h", "help"},
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

void print_help_information() {
	const char help[] = \
	"Usage: MicroNCC [options] [files]\n"
	"Options:\n"
	"  --print-syntax-tree  Print the syntax tree of source code\n"
	"  --print-reduce-step  Print reduce step while reducing\n"
	"\n"	
	"This program built for nanos\n"
	"Report bugs to <https://github.com/NJUCS-ComputerSystemLab-2017/MicroNCC>\n";
	printf("%s", help);
	exit(0);
}

void load_opt(int argc, char *argv[]) {
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
			}

		}

		if(match_state == 0) {
			fprintf(stderr, "Unknown Option '%s'.\n", argv[i]);
			exit(0);
		}else if(match_state == 2) {
			vector_push(&cmd_files, &argv[i]);
		}
	}
}

void parse_arguments(int argc, char *argv[]) {
	logd("parse arguments={%d, %s}.\n", argc - 1, dumps_argv(argc, argv));
	vector_init(&cmd_files, sizeof(char *));
	load_opt(argc, argv);
	if(get_onoff_from_arguments(ArgumentHelp))
		print_help_information();
}

int main(int argc, char *argv[])
{
	/*dont't move it*/
	parse_arguments(argc, argv);

	/*init bpool module*/
	init_bpool();

	/*init hash module*/
	init_hash();

	/*init vector module*/
	init_vector();

	/*int front module*/
	//init_front();

	/*init your own module*/

	logd("normal exit.\n");
    return 0;
}

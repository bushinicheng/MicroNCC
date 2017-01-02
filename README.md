# compiler work

##introduction
* build this project
 * `make`
* run and print syntax tree
 * `./compiler filename --print-ast`
 * or `cat filename | ./compiler --print-ast`

##compiling environment
* OS
 * ubuntu 15.10 64bit
* compiler
 * gcc version 5.2.1 20151010
* related script
 * shell script : test.sh
 * python script : genast.py(important)

##example
```
/*
 * // c style comment
 */

struct typeA {
	int a, b, *c, d[10][20][30][40];//arbitrary dimension of array
	struct typeB {
		int z;
		struct typeC {//arbitrary depth of nested struct
			int *p;
		} a, b, c;
	} **t[15];
};

int myfunc(struct typeA *a[2], int p, int z) {//arbitrary number of arguments
	int ret = p * z;
	if(p > z) {
		a[0]->a = 1;
		a[0][0].b = p & z;
	}

	return ret;
}

int main(int argc, char **argv) {
	return 0;
}

```

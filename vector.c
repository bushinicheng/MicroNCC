#include "common.h"
#include "vector.h"
#include <time.h>

typedef struct tagVectorTest {
	int num;
} VectorTest;

int init_vector()
{
#ifdef __DEBUG__
	srand(time(NULL));
	UNIT_TEST_START;
	const int test_size = 5000;
	int ans[test_size], pans = 0;
	VectorTest *pvt, vt;
	vector_init(VectorTest, pvt);
	for(int i = 0; i < test_size; i++)
	{
		vt.num = rand();
		if(rand()%3==0 && pans > 0)
		{
			pans --;
			vector_pop(pvt);
		}
		else
		{
			ans[pans++] = vt.num;
			vector_push(pvt, vt);
		}
	}

	/*test push operation*/
	for(int i = 0; i < pans; i++)
	{
		UNIT_TEST_ASSERT((pvt[i].num == ans[i]), \
			"\nfail at case #%d, should be '%d' but got '%d'", i, ans[i], pvt[i].num);
	}

	UNIT_TEST_ASSERT(pans == vector_size(pvt), \
			"\ntest failed: inconsistent vector size..");

	vector_free(pvt);

	UNIT_TEST_END;

#endif
	return 0;
}

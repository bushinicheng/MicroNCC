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
	bool pass = true;
	const int test_size = 5000;
	int ans[test_size], pans = 0;
	logd("[unit test]func:%s, line:%d...", __func__, __LINE__);
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
		if(pvt[i].num != ans[i])
		{
			logd("\ntest failed at case #%d.", i);
			loge("\nshould be '%d' but got '%d'", ans[i], pvt[i].num);
			pass = false;
			break;
		}
	}

	if(pans != vector_size(pvt))
		logd("\ntest failed: conflicting vector size..");

	vector_free(pvt);

	if(pass)
		logG("PASS\n");
	else
		logd("\n");

#endif
	return 0;
}

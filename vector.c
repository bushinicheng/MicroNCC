#include "common.h"
#include "vector.h"

typedef struct tagVectorTest {
	int num;
} VectorTest;

int init_vector()
{
#ifdef __DEBUG__
	bool pass = true;
	logd("[unit test]func:%s, line:%d...", __func__, __LINE__);
	VectorTest *pvt, vt;
	vector_init(VectorTest, pvt);
	for(int i = 0; i < 5000; i++)
	{
		vt.num = i;
		vector_push(VectorTest, pvt, vt);
	}

	do {
		/*test push operation*/
		for(int i = 0; i < 5000; i++)
		{
			if(pvt[i].num != i)
			{
				logd("\ntest failed at case #%d (push).", i);
				loge("\nshould be '%d' but got '%d'", i, pvt[i].num);
				pass = false;
				break;
			}
		}

		if(!pass)
			break;

		/*test pop operation*/
		for(int i = 0; i < 2500; i++)
			vector_pop(pvt);

		for(int i = 0; i < 2500; i++)
		{
			vt.num = i + 5000;
			vector_push(VectorTest, pvt, vt);
		}

		for(int i = 0; i < 2500; i++)
		{
			if(pvt[i+2500].num != i+5000)
			{
				logd("\ntest failed at case #%d (pop).", i);
				loge("\nshould be '%d' but got '%d'", i, pvt[i].num);
				pass = false;
				break;
			}
		}

		vector_free(pvt);
	} while(0);

	if(pass)
		logG("PASS\n");
	else
		logd("\n");

#endif
	return 0;
}

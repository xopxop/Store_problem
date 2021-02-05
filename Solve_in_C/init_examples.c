#include "program.h"

static t_product *fillProduct(const char *name, const char *code, const float price)
{
	t_product *product = (t_product*)malloc(sizeof(t_product));

	assert(product);
	product->name = strdup(name);
	product->code = strdup(code);
	product->price = price;
	return (product);
}

t_product **initProducts(void)
{
	static t_product *productList[6];

	if (productList[0] == NULL)
	{
		productList[0] = fillProduct("Milk", "P1", 1.99);
		productList[1] = fillProduct("Sour Milk", "P2", 2.05);
		productList[2] = fillProduct("Cream", "P3", 3.59);
		productList[3] = fillProduct("Yoghurt", "P4", 4.99);
		productList[4] = fillProduct("Buttermilk", "P5", 3.1);
		productList[5] = NULL;
	}
	return (productList);
}

static t_batchSize *fillBatchSize(const char *code, const unsigned int size)
{
	t_batchSize *batchSize = (t_batchSize*)malloc(sizeof(t_batchSize));

	assert(batchSize);
	batchSize->code = strdup(code);
	batchSize->size = size;
	return (batchSize);
}

t_batchSize **initBatchSizes(void)
{
	static t_batchSize *batchSizes[8];

	if (batchSizes[0] == NULL)
	{
		batchSizes[0] = fillBatchSize("BS1", 20);
		batchSizes[1] = fillBatchSize("BS2", 30);
		batchSizes[2] = fillBatchSize("BS3", 40);
		batchSizes[3] = fillBatchSize("BS4", 50);
		batchSizes[4] = fillBatchSize("BS5", 100);
		batchSizes[5] = fillBatchSize("BS6", 20);
		batchSizes[6] = fillBatchSize("BS7", 50);
		batchSizes[7] = NULL;
	}
	return (batchSizes);
}

static t_productBatchSize *fillProductBatchSize(const char *productCode, const char *batchSizeCode)
{
	t_productBatchSize *productBatchSize = (t_productBatchSize*)malloc(sizeof(t_productBatchSize));

	assert(productBatchSize);
	productBatchSize->productCode = strdup(productCode);
	productBatchSize->batchSizeCode = strdup(batchSizeCode);
	return (productBatchSize);
}

t_productBatchSize **initProductBatchSize(void)
{
	static t_productBatchSize *productBatchSize[8];

	if (productBatchSize[0] == NULL)
	{
		productBatchSize[0] = fillProductBatchSize("P1", "BS6");
		productBatchSize[1] = fillProductBatchSize("P2", "BS1");
		productBatchSize[2] = fillProductBatchSize("P2", "BS2");
		productBatchSize[3] = fillProductBatchSize("P2", "BS3");
		productBatchSize[4] = fillProductBatchSize("P3", "BS4");
		productBatchSize[5] = fillProductBatchSize("P3", "BS5");
		productBatchSize[6] = fillProductBatchSize("P5", "BS7");
		productBatchSize[7] = NULL;
	}
	return (productBatchSize);
}

static t_batchQuantity *fillBatchQuantity(const char *productCode, unsigned int quantity)
{
	t_batchQuantity *batchQuantity = (t_batchQuantity*)malloc(sizeof(t_batchQuantity));

	assert(batchQuantity);
	batchQuantity->productCode = strdup(productCode);
	batchQuantity->quantity = quantity;
	return (batchQuantity);
}

t_batchQuantity **initBatchQuantity(void)
{
	static t_batchQuantity *batchQuantity[5];

	if (batchQuantity[0] == NULL)
	{
		batchQuantity[0] = fillBatchQuantity("P1", 20);
		batchQuantity[1] = fillBatchQuantity("P2", 500);
		batchQuantity[2] = fillBatchQuantity("P3", 40);
		batchQuantity[3] = fillBatchQuantity("P4", 234);
		batchQuantity[4] = NULL;
	}
	return (batchQuantity);
}

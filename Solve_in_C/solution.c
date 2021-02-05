#include "program.h"

unsigned int NbOfProducts(t_product **listOfProduct)
{
	unsigned int i = 0;

	while (listOfProduct[i])
		i++;
	return (i);
}

int findingSizeOfSelectedList(const char *productCode, t_productBatchSize **listOfProductBatchSize)
{
	int ct = 0;
	int i = -1;
	while (listOfProductBatchSize[++i])
		if (strcmp(listOfProductBatchSize[i]->productCode, productCode) == 0)
			ct++;
	return (ct);
}

t_productBatchSize **singleProduct_selectedBatches(const char *productCode, t_productBatchSize **listOfProductBatchSize)
{
	int size = findingSizeOfSelectedList(productCode, listOfProductBatchSize);
	if (size == 0)
		return (NULL);
	t_productBatchSize **selectedList = (t_productBatchSize**)malloc(sizeof(t_productBatchSize) * (size + 1));
	assert(selectedList);
	int j = 0;
	for (int i = 0; listOfProductBatchSize[i]; i++)
		if (strcmp(listOfProductBatchSize[i]->productCode, productCode) == 0)
			selectedList[j++] = listOfProductBatchSize[i];
	selectedList[j] = NULL;
	return (selectedList);
}

int singleProduct_batchQuantity(const char *productCode, t_batchQuantity **listOfBatchQuantity)
{
	for (int i = 0; listOfBatchQuantity[i]; i++)
		if (strcmp(listOfBatchQuantity[i]->productCode, productCode) == 0)
			return ((int)listOfBatchQuantity[i]->quantity);
	return (DEFAULT_QUANTITY);
}

t_batchSize *findBatchSize(const char *batchSizeCode, t_batchSize **batchSizes)
{
	for (int i = 0; batchSizes[i]; i++)
		if (strcmp(batchSizes[i]->code, batchSizeCode) == 0)
			return (batchSizes[i]);
	return (NULL);
}

char *maxBatchSize(t_batchSize **batchSizes, t_productBatchSize **selectedBatches)
{
	int i = -1;
	t_batchSize *ptr = findBatchSize(selectedBatches[++i]->batchSizeCode, batchSizes);
	assert(ptr);
	t_batchSize *temp;

	temp = NULL;
	while (selectedBatches[++i])
	{
		temp = findBatchSize(selectedBatches[i]->batchSizeCode, batchSizes);
		assert(temp);
		if (temp->size > ptr->size)
			ptr = temp;
	}
	return (ptr->code);
}

char *minBatchSize(t_batchSize **batchSizes, t_productBatchSize **selectedBatches)
{
	int i = -1;
	t_batchSize *ptr = findBatchSize(selectedBatches[++i]->batchSizeCode, batchSizes);
	assert(ptr);
	t_batchSize *temp;

	temp = NULL;
	while (selectedBatches[++i])
	{
		temp = findBatchSize(selectedBatches[i]->batchSizeCode, batchSizes);
		assert(temp);
		if (temp->size < ptr->size)
			ptr = temp;
	}
	return (ptr->code);
}

char *findingBatchSizeCode(t_productBatchSize **selectedBatches, t_batchSize **batchSizes, char *productCode, bool batchSizeSelection)
{
	char buf[256];

	if (selectedBatches == NULL)
	{
		bzero(buf, 256);
		strcpy(buf, DEFAULT_STRING);
		strcat(buf, productCode);
		return (strdup(buf));
	}
	if (batchSizeSelection == true)
		return strdup(maxBatchSize(batchSizes, selectedBatches));
	return strdup(minBatchSize(batchSizes, selectedBatches));
}

int findingBatchSize(char *batchSizeCode, t_batchSize **batchSizes)
{
	for (int i = 0; batchSizes[i]; i++)
		if (strcmp(batchSizes[i]->code, batchSizeCode) == 0)
			return (batchSizes[i]->size);
	return (DEFAULT_SIZE);
}

t_order *createOrderOfASingleProduct(t_product *product, t_productBatchSize **selectedBatches, t_batchSize **batchSizes, int quantity, bool batchSizeSelection)
{
	t_order *singleProduct = (t_order*)malloc(sizeof(t_order));

	assert(singleProduct);
	singleProduct->productCode = strdup(product->code);
	singleProduct->productName = strdup(product->name);
	singleProduct->batchSizeCode = findingBatchSizeCode(selectedBatches, batchSizes, singleProduct->productCode, batchSizeSelection);
	singleProduct->batchSize = findingBatchSize(singleProduct->batchSizeCode, batchSizes);
	singleProduct->batchQuantity = quantity;
	singleProduct->price = product->price;
	(selectedBatches) ? free(selectedBatches) : 0;
	return (singleProduct);
}

/* This is the solution function */

t_order **solution(t_product **listOfProduct, t_batchSize **listOfBatchSizes, t_productBatchSize **listOfProductBatchSize, t_batchQuantity **listOfBatchQuantity, bool batchSizeSelection)
{
	int size = NbOfProducts(listOfProduct);
	assert(size > 0);
	t_order **order = (t_order**)malloc(sizeof(t_order*) * (size + 1));
	assert(order);
	int i = -1;
	while (++i < size)
		order[i] = createOrderOfASingleProduct(
			listOfProduct[i],
			singleProduct_selectedBatches(listOfProduct[i]->code, listOfProductBatchSize),
			listOfBatchSizes,
			singleProduct_batchQuantity(listOfProduct[i]->code, listOfBatchQuantity),
			batchSizeSelection);
	order[i] = NULL;
	return (order);
}

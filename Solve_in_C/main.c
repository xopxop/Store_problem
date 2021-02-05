#include "program.h"

void printOrder(t_order **order)
{
	printf("Orders\n");
	printf("|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|\n", "Product Code", "Product Name", "Batch Size Code", "Batch Size", "Batch quantity", "Price per Unit");
	for (int i = 0; order[i]; i++)
		printf("|%-20s|%-20s|%-20s|%20d|%20d|%20.2f|\n", order[i]->productCode, order[i]->productName, order[i]->batchSizeCode, order[i]->batchSize, order[i]->batchQuantity, order[i]->price);
}

int printUsage(void)
{
	printf("Error: Usage: ./my_program [1 or 0]\n");
	return (0);
}

bool isValidParameter(char *str)
{
	if (strlen(str) > 1)
		return (false);
	if (str[0] != '0' && str[0] != '1')
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	bool batchSizeSelection;

	if (ac > 2)
		return (printUsage());
	if (ac == 1)
		batchSizeSelection = true;
	else if (isValidParameter(av[1]) == false)
		return (printUsage());
	else
		batchSizeSelection = (av[1][0] == '0') ? false : true;
	t_product **listOfProduct = initProducts();
	t_batchSize **listOfBatchSizes = initBatchSizes();
	t_productBatchSize **listOfProductBatchSize = initProductBatchSize();
	t_batchQuantity **listOfBatchQuantity = initBatchQuantity();
	t_order **order = solution(listOfProduct, listOfBatchSizes, listOfProductBatchSize, listOfBatchQuantity, batchSizeSelection);
	printOrder(order);
	cleanupAllOrder(order);
	cleanupListOfProduct(listOfProduct);
	cleanupListOfBatchSizes(listOfBatchSizes);
	cleanupListOfProductBatchSize(listOfProductBatchSize);
	cleanupListOfBatchQuantity(listOfBatchQuantity);
	return (0);
}

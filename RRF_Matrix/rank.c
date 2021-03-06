#include <stdio.h>
#define row 4
#define clmn 5


typedef struct{
	float entries[row][clmn];
}Matrix;

void print_Matrix(Matrix *matrix);
void build_Matrix(Matrix *matrix);
void row_divide(Matrix *matrix, float divider, int r_num);
void row_add(Matrix *matrix, int r_base, int r_adding, float r_scaler);
int min(int a, int b);

int main(void)
{
	Matrix A; build_Matrix(&A);
	printf("\n Row reduced form:\n-----------------\n");
	
	for(int i=0; i<min(clmn,row); i++)
	{
		int zero_row =1, adder=0;
		
		for(int j=0; j<clmn; j++)
		{
			if(A.entries[i][j])
			{		
				zero_row = 0; adder = j;
				row_divide(&A, A.entries[i][j], i);				
				break;
			}
		}
		if(zero_row)
		{
			continue;
		}

		for(int j=0; j<row; j++)
		{
			if(i-j)
			{
				row_add(&A, j, adder, -A.entries[j][i]);
			}
		}
	}
	print_Matrix(&A);
}

int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}

void row_divide(Matrix *matrix, float divider, int r_num)
{
	for(int i=0; i<clmn; i++)
	{
		matrix->entries[r_num][i] /= divider;
	}
}

void row_add(Matrix *matrix, int r_base, int r_adding, float r_scaler)
{
	for(int i=0; i<clmn; i++)
	{
		matrix->entries[r_base][i] += matrix->entries[r_adding][i] * r_scaler;
	}
}
void build_Matrix(Matrix *matrix)
{
	for(int i=0; i<row; i++)
	{		
		for(int j=0; j<clmn; j++)
		{
			scanf("%f", &(matrix->entries[i][j]));
		}
	}	
}

void print_Matrix(Matrix *matrix)
{
	for(int i=0; i<row; i++)
	{		
		for(int j=0; j<clmn; j++)
		{
			printf("%.2f ", matrix->entries[i][j]);
		}
		printf("\n");	
	}
}
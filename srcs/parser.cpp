#include <iostream>

double *prod_Token(const char *expression, int *index);
double *sum_Token(const char *expression, int *index);
double ft_atoi(const char *str, int *i);
double get_Number(const char *str, int *i);
int get_Expose(const char *expression, int *index);

double get_Number(const char *str, int *i) {
    double result;
    double weight;
    double decimal;

    result = 0;
    while (str[*i] >= '0' && str[*i] <= '9')
    {
        result = result * 10 + (str[*i] - '0');
        *i += 1;
    }
    if (str[*i] == '.') {
        *i += 1;
        weight = 1;
        while (str[*i] >= '0' && str[*i] <= '9')
        {
            weight = weight / 10;
            decimal = (str[*i] - '0') * weight;
            result = result + decimal;
            *i += 1;
        }  
    }
    return result;
}

int get_Expose(const char *expression, int *index) {
    int expose;

    expose = -1;
    if (expression[*index] == 'X' || expression[*index] == 'x') {
        expose = 0;
        *index += 1;
        if (expression[*index] == '^') {
            *index += 1;
            expose = (int)ft_atoi(expression, index);
        }
        else
            expose = 1;
        if (expose > 2 || expose < 0) {
           return 1;
    }
    }
    return expose;
}

double ft_atoi(const char *str, int *i) {
	int neg;
	double result;
    double sum;

	result = 0;
	neg = 1;
    if (str[*i] == '-')
	{
		neg = -1;
		*i += 1;
	}
	else if (str[*i] == '+')
		*i += 1;
    if (str[*i] >= '0' && str[*i] <= '9'){
        result = get_Number(str, i);
    }
    else if (str[*i] == '(') {
        *i += 1;
        sum = sum_Token(str, i);
        *i += 1;
        return(sum);
    }
	
	return (result * neg);
}

// token == '-' || token == '+'
double *sum_Token(const char *expression, int *index) {

    // sum become sum[3]
    double sum[3];
    double sum2[3];
    // double res[3];
    // res[0] = 0;
    // res[1] = 0;
    // res[2] = 0;

    sum = prod_Token(expression, index);
    // while (expression[*index] == '+' || expression[*index] == '-') {
    //     *index += 1;
    //     if (expression[*index - 1] == '+') {
    //         sum2 = prod_Token(expression, index);
    //         sum = sum + sum2;
    //     }  
    //     else {
    //         sum2 = prod_Token(expression, index);
    //         sum = sum - sum2;
    //     }
    // }
    return sum;
}

// token == '*' || token == '/'
double *prod_Token(const char *expression, int *index) {

    double prod[3];
    double aled;
    // double prod2[3];
    // int expose;

    aled = ft_atoi(expression, index);
    // if (expression[*index] == X || ^ || special)
    // while (expression[*index] == '*' || expression[*index] == '/') {
    //     *index += 1;
    //     expose = get_Expose(expression, index);
    //     if (expose == -1) {
    //         if (expression[*index - 1] == '*') {
    //             prod = ft_atoi(expression, index);
    //             prod = prod * prod2;
    //         }
    //         else {
    //             prod = ft_atoi(expression, index);
    //             prod = prod / prod2;
    //         }
    //     }
        // if (expose == 0) {
        //     prod = prod * 1;
        // }
        // if (expose == 1) {
        //     prod = prod * 1;
        // }
        // if (expose == 2) {
        //     prod = prod * 1;
        // }
    }
    return prod;
}

void parser(char *expression) {

    // Transformer tous les sum / pro / res par x[3]
    // On crée un arbre pour chaque dégré d'inconnu
    double res[3];
    res[0] = 0;
    res[1] = 0;
    res[2] = 0;
    
    int index = 0;

    res = sum_Token(expression, &index);
    std::cout << "Result : " << result << std::endl;
}
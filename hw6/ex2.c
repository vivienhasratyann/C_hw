#include <stdio.h>

struct Complex {
    int real;
    int img;
};

struct Complex add(struct Complex c1, struct Complex c2){
    struct Complex result;
    result.real = c1.real + c2.real;
    result.img = c1.img + c2.img;
    return result;

}

struct Complex mult(struct Complex c1, struct Complex c2){
    struct Complex result; // յահաաա հիմա գնամ մատանալիզի տետրի հետևից :// 
    result.real = (c1.real * c2.real) - (c1.img * c2.img);
    result.img = (c1.real * c2.img) + (c1.img * c2.real);
    return result;
}

void display(struct Complex c){
    printf("%d + %di\n", c.real, c.img); // floating-point number with 2 decimal places. Frist for real part and second imaginary part 
}

int main(){
    struct Complex c1, c2, sum, product;

    printf("Input first complex number: \n");
    scanf("%d %d", &c1.real, &c1.img);

    printf("Input first complex number: \n");
    scanf("%d %d", &c2.real, &c2.img);
    
    sum = add(c1, c2);
    product = mult(c1, c2);

    printf("Sum: \n");
    display(sum);

    printf("Product: \n");
    display(product);


    return 0;
}
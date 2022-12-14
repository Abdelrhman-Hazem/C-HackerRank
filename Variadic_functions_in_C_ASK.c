#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000
#include <stdio.h>


#define my_func10(...) sum1(__VA_ARGS__, 0)
#define my_func9(...) my_func10(__VA_ARGS__, 0)
#define my_func8(...) my_func9(__VA_ARGS__, 0)
#define my_func7(...) my_func8(__VA_ARGS__, 0)
#define my_func6(...) my_func7(__VA_ARGS__, 0)
#define my_func5(...) my_func6(__VA_ARGS__, 0)
#define my_func4(...) my_func5(__VA_ARGS__, 0)
#define my_func3(...) my_func4(__VA_ARGS__, 0)
#define my_func2(...) my_func3(__VA_ARGS__, 0)
#define my_func1(...) my_func2(__VA_ARGS__, 0)
#define VAR_FUNC(_1, _2, _3,_4,_5,_6,_7,_8,_9,_10,_11, NAME, ...) NAME
#define sum(...) VAR_FUNC(__VA_ARGS__, sum1, my_func10, my_func9, my_func8, my_func7, my_func6, my_func5, my_func4, my_func3, my_func2, my_func1)(__VA_ARGS__)

#define minn10(...) min1(__VA_ARGS__, 0)
#define minn9(...) minn10(__VA_ARGS__, 0)
#define minn8(...) minn9(__VA_ARGS__, 0)
#define minn7(...) minn8(__VA_ARGS__, 0)
#define minn6(...) minn7(__VA_ARGS__, 0)
#define minn5(...) minn6(__VA_ARGS__, 0)
#define minn4(...) minn5(__VA_ARGS__, 0)
#define minn3(...) minn4(__VA_ARGS__, 0)
#define minn2(...) minn3(__VA_ARGS__, 0)
#define minn1(...) minn2(__VA_ARGS__, 0)
#define min(...) VAR_FUNC(__VA_ARGS__, min1, minn10, minn9, minn8, minn7, minn6, minn5, minn4, minn3, minn2, minn1)(__VA_ARGS__)

#define maxx10(...) max1(__VA_ARGS__, 0)
#define maxx9(...) maxx10(__VA_ARGS__, 0)
#define maxx8(...) maxx9(__VA_ARGS__, 0)
#define maxx7(...) maxx8(__VA_ARGS__, 0)
#define maxx6(...) maxx7(__VA_ARGS__, 0)
#define maxx5(...) maxx6(__VA_ARGS__, 0)
#define maxx4(...) maxx5(__VA_ARGS__, 0)
#define maxx3(...) maxx4(__VA_ARGS__, 0)
#define maxx2(...) maxx3(__VA_ARGS__, 0)
#define maxx1(...) maxx2(__VA_ARGS__, 0)
#define max(...) VAR_FUNC(__VA_ARGS__, max1, maxx10, maxx9, maxx8, maxx7, maxx6, maxx5, maxx4, maxx3, maxx2, maxx1)(__VA_ARGS__)


int  sum1 (int count,int a,int b,int c,int d,int e, int f, int g, int h,int i, int j) {
    int arr[10]={a,b,c,d,e,f,g,h,i,j};
    int sum=0;
    for(int i=0;i<count;i++)sum+=arr[i];
    return sum;
}

int min1(int count,int a,int b,int c,int d,int e, int f, int g, int h,int i, int j) {
    int arr[10]={a,b,c,d,e,f,g,h,i,j};
    int min=arr[0];
    for(int i=0;i<count;i++)if(arr[i]<min)min=arr[i];
    return min;
}

int max1(int count,int a,int b,int c,int d,int e, int f, int g, int h,int i, int j) {
    int arr[10]={a,b,c,d,e,f,g,h,i,j};
    int max=arr[0];
    for(int i=0;i<count;i++)if(arr[i]>max)max=arr[i];
    return max;
}

int test_implementations_by_sending_three_elements() {
    srand(time(NULL));
    
    int elements[3];
    
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending following three elements:\n");
    for (int i = 0; i < 3; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(3, elements[0], elements[1], elements[2]);
    int minimum_element = min(3, elements[0], elements[1], elements[2]);
    int maximum_element = max(3, elements[0], elements[1], elements[2]);

    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 3; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }
        
        if (elements[i] > maximum_element) {
            return 0;
        }
        
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}

int test_implementations_by_sending_five_elements() {
    srand(time(NULL));
    
    int elements[5];
    
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending following five elements:\n");
    for (int i = 0; i < 5; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    int minimum_element = min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    int maximum_element = max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    
    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 5; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }
        
        if (elements[i] > maximum_element) {
            return 0;
        }
        
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}

int test_implementations_by_sending_ten_elements() {
    srand(time(NULL));
    
    int elements[10];
    
    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[5] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[6] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[7] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[8] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[9] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    
    fprintf(stderr, "Sending following ten elements:\n");
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }
    
    int elements_sum = sum(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    int minimum_element = min(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    int maximum_element = max(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    
    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
    
    int expected_elements_sum = 0;
    for (int i = 0; i < 10; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }
        
        if (elements[i] > maximum_element) {
            return 0;
        }
        
        expected_elements_sum += elements[i];
    }
    
    return elements_sum == expected_elements_sum;
}

int main ()
{
    int number_of_test_cases;
    scanf("%d", &number_of_test_cases);
    
    while (number_of_test_cases--) {
        if (test_implementations_by_sending_three_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
        
        if (test_implementations_by_sending_five_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
        
        if (test_implementations_by_sending_ten_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
    }
    
    return 0;
}

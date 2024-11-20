#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) ((x * x * x) - (5 * x) + (3))
#define df(x) ((3 * x * x) - (5))

/*
    aim -> WAP in C for Newton Raphson Method

    theory -> 
    newton raphson method is an iterative algorithm to find the root of the
    real value function f(x) based on its derivative df(x)

    ALGORITHM ->
        newton raphson method is an iterative algorithm to find the root of the
        real value function f(x) based on its derivative df(x) it uses initial guess such that f(x) is consecutively (-ve , +ve) or
        (+ve , -ve) not (-ve , -ve) or (+ve , +ve)

        use the iterative foumula as : 
            Xn+1= Xn - (f(Xn) / df(Xn))
        it starts from X0 which is the first approximation

        update the iterative formula for n and Xn

        repeat the iterations till | Xn+1 - Xn | is less than the tolerance e

        stop if the max limit of the iterations is reached


        EDGE CASES ->

            - zero derivative ->
                if (df(x) == 0) ->
                    - give division by zero ERROR
                    - if checking for (df(x) = ) before the update
                    - use a fallback method (e.g -> bisection method) 
                    for this iteration

            - non convergence -> 
                the method may fail to converge if -> 
                     - the function is not continuous or differentiable
                     - the initial guess is far from the root
                     - the derivative changes sign near the root (oscillation)
            
            - slower convergence ->
                the convergence might be slow if the derivative (df(x))
                is small

            - no roots exits ->
            if the function does not have a root , the method may diverge

            - multiple roots ->
                if the function has multiple roots , the result depends on the 
                initial guess , different guesses may converge to different 
                roots


        CONVERGENCE ->

            quadratic convergence (= 2)

            method fails to converge ->

                - poor intial gues ->
                    If X0 s far from the root , the method might diverge or 
                    converge to a different root

                - flat derivative ->
                    if  |df(x)| is very small near the initial guess 
                    the step size becomes very large leading to divergence

                - oscillation ->
                    The method may oscillate indefinitely if the function behaves 
                    erratically or has inflection points near the root

                - discontinuos function ->
                    for fns whith discontinuties , convergence is not guaranteed

                - complex roots ->
                    the method may fail to converge to a real root if the root 
                    is complex unless extended to complex numbers

            methods to improve convergence ->

                - chose a better initial guess ->
                    start with a good initial approximation use graphs , hit and trial
                    method etc to get a good aprroximation

                - modify the function:
                    in cases of multiple roots , divide f(x) by its 
                    greatest common divisor (GCD) to reduce multiplicity

                - fallback mechanism (use a different method) ->
                    switch to a more robust but slower method 
                    (like the bisection method) if the newton - raphson method 
                    fails to converge
                    
                - limit iterations ->
                    impose a maximum number of iterations to avoid 
                    infinite loops

                
            ALGORITHM ->

                var used ->

                f(x) = function or equation defined as a macro
                df(x) = derivative of the function or equation defined as a macro
                e = 0.0001 (error tolerance)
                x1 = first initial guess
                x2 = second initial guess
                N = number of iterations
                f1 = f(x1) = value of function at x1
                f2 = f(x2) = value of function at x2
                x0 = initial aprroximation
                f0 = f(x0) = value of function at x0 (initial approximation)
                df0 = df(x0) = value of derivative of a function at x0 (initial approximation)

                
                define the function f(x) as a macro
                define the derivative of the function df(x) as a macro
                define the error tolerance e = 0.001

                take user input for initial guess x1 , x2
                take user input for number of iterations N

                intialise f1 = f(x1)
                initialse f2 = f(x2)

                if (f1 * f2 > 0) ->
                    print "incorrect initial guess"
                    EXIT

                else ->

                    if (fabs(f1) < fabs(f2)) ->
                        x0 = x1
                    else ->
                        x0 = x2

                    [START OF DO WHILE LOOP]
                    do ->
                        f0 = f(x0)
                        df0 = df(x0)
                        x1 = x0 - (fx0 / df0)
                        print "iteration i , root x1 , val of fn f1"
                        x0 = x1
                        i = i + 1
                        if (N < i) ->
                            print "not convergent"
                            EXIT
                        f1 = f(x1)
                        [END OF DO WHILE LOOP]
                        while (fabs(f0 / df0) > e) ->
                            print "hence the root is x1"

            TEST CASE ->

                INPUT -> 
                    f(x) = ((x * x * x) - (5 * x) + (3))
                    df(x) = ((3 * x * x) - (5))
                    initial approximations = (x1 = 0 , x2 = 1)
                    number of iterations = N  = 5

                OUTPUT ->
                    NEWTON RAPHSON METHOD
                    enter two initial guesses (x1 , x2) : 0 1 
                    enter the number of iterations (N) : 5
                    iteration : 1   root of the fn : 0.600000       value of the fn : 0.000000
                    iteration : 2   root of the fn : 0.655102       value of the fn : 0.216000
                    iteration : 3   root of the fn : 0.656619       value of the fn : 0.005632
                    iteration : 4   root of the fn : 0.656621       value of the fn : 0.000005
                    hence the root is : 0.656621

*/


int main(int argc , char *argv[]){
    float x0 , x1 , x2 , f0 , f1 , f2 , df0 , e = 0.0001;
    int N = 0 , i = 1;
    printf("\n\tNEWTON RAPHSON METHOD\t\n");
    printf("\nenter two initial guesses (x1 , x2) : ");
    scanf("%f %f" , &x1 , &x2);
    printf("\nenter the number of iterations (N) : ");
    scanf("%d" , &N);
    f1 = (x1);
    f2 = f(x2);
    if (f1 * f2 > 0){
        printf("\nincorrect initial guess\n");
        printf("\ntry again\n");
        return -1;
    }
    else{
        if (fabs(f1) < fabs(f2)){
            x0 = x1;
        }
        else{
            x0 = x2;
        }
        do {
            f0 = f(x0);
            df0 = df(x0);
            x1 = x0 - (f0 / df0);
            printf("\niteration : %d\troot of the fn : %f\tvalue of the fn : %f\t\n" , i , x1 , f1);
            x0 = x1;
            i++;
            if (N < i){
                printf("\nnot convergent\n");
                return -1;
            }
            f1 = f(x1);
        } while (fabs(f0 / df0) > e);

        printf("\n\nhence the root is : %f\n\n" , x1);
    }
    return 0;
}


#include "solution.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>


struct Monome create_Monome(double coefficient,double puissance){
    struct Monome monome;
    monome.coefficient=coefficient;
    monome.puissance=puissance;
    return monome;
}

struct Node *create_Polynome(){
    struct Monome monome=create_Monome((double)0,(double)0);
    struct Node *newPolynome;
    newPolynome = (struct Node*)malloc(sizeof(struct Node));
    newPolynome->monome=monome;
    newPolynome->next=NULL;
    newPolynome->prev=NULL;
}

struct Node *add_Monome_To_Polynome(struct Monome monome, struct Node *head) {
    struct Node *temp;
    temp = head;

    if (temp->monome.coefficient == 0) {
        temp->monome=monome;
        return head;
    } 
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        struct Node *newNode = create_Polynome();
        newNode->monome = monome;
        newNode->next = NULL;
        newNode->prev = temp;
        
        temp->next = newNode;
        return head;
    }
}


void display_Polynome(struct Node *head){
    struct Node *temp;
    temp=head;
    while(temp != NULL){
        printf("%lf(x^%lf)",temp->monome.coefficient,temp->monome.puissance);
        temp=temp->next;

        if(temp)
            printf("+");
    }
    printf("\n");
}

struct Node *calculate_Sum_Of_Two_Polynome(struct Node *head1, struct Node *head2) {
    struct Node *temp1, *temp2, *result = create_Polynome();
    temp1 = head1;
    temp2 = head2;

    while (temp1) {
        double c=temp1->monome.coefficient + temp2->monome.coefficient;
        double p=temp1->monome.puissance;
        result = add_Monome_To_Polynome(create_Monome(c,p), result);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return result;
}


struct Node *calculate_Multiplication_Of_TwoPolynome(struct Node *head1,struct Node *head2){
    struct Node *temp1, *temp2, *result = create_Polynome();
    temp1 = head1;
    temp2 = head2;

    while (temp1) {
        double c=temp1->monome.coefficient * temp2->monome.coefficient;
        double p=temp1->monome.puissance+temp1->monome.puissance;
        result = add_Monome_To_Polynome(create_Monome(c,p), result);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return result;
}
void solve_Polynome(struct Node *head);
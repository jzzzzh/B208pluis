#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int N = 32;
typedef struct hashmap
{
    int num = 0;
    struct hashmap *next = NULL;
}hashmap;
    hashmap *h[N];
    int module(int n)
    {
        return n & (N - 1);
    }
    int main(void)
    {
        int number;
        while (cin >> number)
        {
            int mod = module(number);
            hashmap *now = h[mod];
            while (now->next)
            {
                now = now->next;
            }
            hashmap *temp = new hashmap;
            temp->next = NULL;
            temp->num = number;
            now->next = temp;
        }
        cout << "search: ";
        int n;
        cin >> n;
        int mod = module(n);
        hashmap *now = h[mod];
        while (now->next != NULL)
        {
            if (now->next->num == n)
            {
                cout << "exist" << endl;
                break;
            }
            now = now->next;
        }
        if (now->next == NULL)
        {
            cout << "failed find" << endl;
        }
        return 0;
    }


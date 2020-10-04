#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool shouldSwap(char str[], int start, int cur)
{
    for (int i = start; i < cur; i++)
        if (str[i] == str[cur])/*若是發現重複字元，則回傳假值，表示不做交換，跳過"deplicate"情況"*/
            return 0;
    return 1;
}

// Prints all distinct permutations in str[0..n-1]
void getP(char str[], int index, int n)/*打印出排列組合之集合*/
{
    if (index >= n) {/*整個字串的排列都決定好後，將其打印*/
        cout << str << endl;
        return;
    }

    for (int i = index; i < n; i++) {
        /*只有當str[i]與str[index]後的任何字元都不匹配時，才會為str[i]執行下一步運算*/
        bool check = shouldSwap(str, index, i);
        if (check) {
            swap(str[index], str[i]);
            getP(str, index + 1, n);/*遞迴概念，透過重複的子交換來獲得上層的排列集合*/
            swap(str[index], str[i]);
        }
    }
}

int main()
{

    char str[30];
    while(1){
        cin >> str;
        int n = strlen(str);
        getP(str, 0, n);
        cout << "name: 謝霆, ID: 410721312" << endl;
    }
    return 0;
}

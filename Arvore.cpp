#include <bits/stdc++.h>
using namespace std;

typedef struct No
{

    string name;
    vector<No *> filhos;

} No;

No *novoNo(string name)
{
    No *temp = new No;
    temp->name = name;
    return temp;
}

void mostraFolhasArvore(No *root)
{
    for (int i = 0; i < root->filhos.size(); i++)
    {

        if (root->filhos[i]->name[0] >= 65 && root->filhos[i]->name[0] <= 90)
        {
            mostraFolhasArvore(root->filhos[i]);
        }
        else
        {
            cout << root->filhos[i]->name << " ";
        }
    }
}

void mostraArvorePorNivel(No *root)
{
    if (root == NULL)
        return;

    queue<No *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            No *p = q.front();
            q.pop();
            cout << p->name << " ";

            for (int i = 0; i < p->filhos.size(); i++)
                q.push(p->filhos[i]);
            n--;
        }
        cout << endl;
    }
}
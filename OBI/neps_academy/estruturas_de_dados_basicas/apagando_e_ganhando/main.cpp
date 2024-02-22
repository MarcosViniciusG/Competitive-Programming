#include <bits/stdc++.h>

int to_int(char n)
{
	return n-'0';
}

using namespace std;

// & passa por referência
void apaga(string& n, string::iterator& ptr)
{
	/*
	Função que apaga um elemento da lista e "reajusta" o ponteiro
	*/

	// Checa se é o primeiro elemento da string
	if(ptr!=n.begin())
	{
		ptr--;
		auto prev_ptr = ptr;
		ptr++;
		n.erase(ptr);
		ptr = prev_ptr;
	}
	else
	{
		n.erase(ptr);
		ptr = n.begin();
	}
}

int main()
{
	long int N, D;
	string n;
	cin >> N >> D;
	cin.ignore(1, '\n');
	while(N && D)
	{
		getline(cin, n);

		// Laço que percorre o número do começo ao fim enquanto verifica se
		// o próximo número é maior que o número atual e apagá-lo caso for
		auto ptr = n.begin();
		while (ptr!=n.end()-- && D!=0)
		{
			char atual = *ptr;
			ptr++;
			char prox = *ptr;
			ptr--;

			if(to_int(prox) > to_int(atual))
			{
				apaga(n, ptr);
				D--;
			}
			else ptr++;
		}


		// Laço que percorre o número do fim ao começo enquanto verifica se o número anterior é maior
		// que o atual e apagá-lo caso for
		ptr = n.end();
		ptr--;
		while(ptr!=n.begin() && D!=0)
		{

			char atual = *ptr;
			
			ptr--;

			char prev = *ptr;

			ptr++;

			if(to_int(prev) >= to_int(atual))
			{
				apaga(n, ptr);
				D--;
			}
			else ptr++;
		}
		
		cout << n << endl;
		
		cin >> N >> D;
		cin.ignore(1, '\n');
	}
	
	return 0;
}
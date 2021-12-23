#include<iostream>
#include<vector>
#include<string>

using namespace std;

class HillCifer{

	vector<int> key;
	vector<char> plain_text;
	vector<int> plain_value;

	vector<int> get_plain_value()
	{
		for(auto elm : plain_text)
		{
			plain_value.push_back(int(elm) - 65);
		}
		return plain_value;
	}
	
	string cypher(int index)
	{
		string cypher_text = "";

		int c1 = key[0] * plain_value[index] + key[1] * plain_value[index+1];
		
		int c2 = key[2] * plain_value[index] + key[3] * plain_value[index+1];


		cout<<"C"<<index<<" : "<<key[0] <<'*'<< plain_value[index] <<'+'<< key[1] <<'*'<< plain_value[index+1]<<'='<<c1<<endl;
		cout<<"C"<<index+1<<" : "<<key[2] <<'*'<< plain_value[index] <<'+'<< key[3] <<'*'<< plain_value[index+1]<<'='<<c2<<endl;

		c1%=26;
		c2%=26;

		cout<<"\nAfter % 26\n"<<endl;

		cout<<"C"<<index<<" : "<<c1<<endl;
		cout<<"C"<<index+1<<" : "<<c2<<endl;

		cypher_text+= char(c1+65);
		cypher_text+= char(c2+65);

		cout<<"\nCypher Text: "<<cypher_text<<endl<<endl;

		return cypher_text;
	}

	bool odd_size_text()
	{
		return plain_text.size()%2;
	}

	public:

	HillCifer()
	{
		cout<<"\t\t\t\t\t\t*****\t\t\t\t\t\t\n";
		cout<<"***\t\t\t\t\t\tNote\t\t\t\t\t\t***\n";
		cout<<"***\tIf plain text length is odd then 'X' will be added by default to make proper duplets\t***\n";
		cout<<"\t\t\t\t\t\t*****\t\t\t\t\t\t\n";
	}

	void set_key(vector<int> key)
	{
		for(auto elm : key)
		{
			this->key.push_back(elm);
		}
	}

	void set_pt(string plain_text)
	{
		for(auto elm : plain_text)
		{
			this->plain_text.push_back(elm);
		}

		if(odd_size_text())
		{
			this->plain_text.push_back('X');
		}

		get_plain_value();
	}

	void parse()
	{
		string result_text="";

		int length=plain_text.size();

		for(int i=0; i<length; i+=2)
		{
			result_text+=cypher(i);
		}
		
		cout<<"Cypher: "<<result_text;
	}

	void print_plain_text()
	{
		for(auto elm : plain_text)
		{
			cout<<elm<<" ";
		}
		cout<<endl;
	}

	void print_plain_value()
	{
		for(auto elm : plain_value)
		{
			cout<<elm<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	vector<int> key ={2,3,3,6};
	string plain_text = "ATTACK";

	HillCifer h;
	h.set_key(key);
	h.set_pt(plain_text);
	h.print_plain_text();
	h.print_plain_value();
	h.parse();
}
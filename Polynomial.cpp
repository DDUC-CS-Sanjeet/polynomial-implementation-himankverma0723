#include<iostream>
using namespace std;
class Polynomial
{
	int array[100];
	int degree;
	public:
	 	 	Polynomial()
	 	    {
	 		degree=1;
		    }
		    Polynomial(int deg)
		    {
			   degree=deg;
			   degree++;	
		    }
		~Polynomial()
        {
            degree=0; 
        }
        Polynomial operator +(Polynomial d)
		{
			Polynomial p;
			p.degree=this->degree>=d.degree? this->degree:d.degree;
			for(int i=0;i<p.degree;i++)
			{
				if(i>=this->degree)
				  this->array[i]=0;
				if(i>=d.degree)
				  d.array[i]=0;
				  p.array[i]=d.array[i]+this->array[i];  
			}
			return p;
		}
		Polynomial operator -(Polynomial d)
		{
			Polynomial p;
			p.degree=this->degree>=d.degree? this->degree:d.degree;
			for(int i=0;i<p.degree;i++)
			{
				if(i>=this->degree)
				  this-> array[i]=0;
				if (i>=d.degree)
				  d.array[i]=0;
				  p.array[i]=this->array[i]-d.array[i];  
			} 
		    return p;	
	    }
	    Polynomial operator =(Polynomial poly)
		{
			Polynomial p;
			this->degree=poly.degree;
			for(int i=0;i<this->degree;i++)
			  this->array[i]=poly.array[i];
	    }
	    void storePolynomial()
        {
               
            cout<<"\n enter the cofficient in ascending order of power"<<endl;
			for(int i=0;i<degree;i++)
			cin>>array[i];
 	    }
 	    void display()
        {
            cout<<"\n";
            for(int i=0;i<degree;i++)
            {
            	cout<<array[i]<<"X^"<<i;
            	if(i<degree-1)
            	  cout<<" + ";
			}
	    }
};
int main()
{
	int degFirst, degSecond;
	cout<<"Enter degree of first Polynomial.";
    cin>>degFirst;
	cout<<"Enter degree of first Polynomial.";
	cin>>degSecond;
    Polynomial firstPolynomial(degFirst);
    Polynomial secondPolynomial(degSecond);
    Polynomial thirdPolynomial;
  
    firstPolynomial.storePolynomial();
    secondPolynomial.storePolynomial();
   
    thirdPolynomial=firstPolynomial+secondPolynomial;
    Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
    firstPolynomial.display();
    cout<<endl;
    secondPolynomial.display();
    cout<<endl;
    thirdPolynomial.display();
    cout<<endl;
    fourthPolynomial.display();
    return 0;
}

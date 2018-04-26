/* 
 * File:   Term.cpp
 * Purpose: to provide the definition of the class named Term
 * Author: pike
 *
 */
#include <iostream>
#include "Term.h"

// default constructor
Term::Term()
{
    weight = 0;
    query = "";
}
    
// initializes a term with the given query string and weight
Term::Term(string query, long weight)
{
    if (weight < 0)
    {    
        cout << "The weight should be a positive number";
        weight = 0;
    }
    else 
    {
        this->query = query;
        this->weight = weight;
    }    
}
    
// compares the two terms in descending order by weight
int Term::byReverseWeightOrder(Term that)
{
    if (this->weight > that.weight)
        return 1;
    if (this->weight == that.weight)
        return 0;
    else
        return -1;
}

// compares the two terms in lexicographic order by query
int Term::compareTo(Term that)
{
    if (this->query < that.query)
        return 1;
    if (this->query == that.query)
        return 0;
    else
        return -1;    
}

// compares the two terms in lexicographic order but using only the first r characters of each query
int Term::byPrefixOrder(Term that, int r)
{
    if (r < 0)
    {
        cout << "The length of the prefix should be a positive number!" << endl;
        return 2;
    }    
    string thisterm = this->query.substr(0,r);
    string thatterm = (that.query).substr(0,r);
           
    if (thisterm < thatterm)
        return 1;
    if (thisterm == thatterm)
        return 0;
    else
        return -1;
}
    
bool operator>(const Term & T1, const Term & T2)
{
	if (T1.weight > T2.weight) {
		return true;
	}
	else {
		return false;
	}
}

// displays the term in the following format:
// the weight, followed by a tab key, followed by the query
ostream &operator<<(ostream &out, const Term& T)
{
    return (out << T.weight << "\t" << T.query );
}

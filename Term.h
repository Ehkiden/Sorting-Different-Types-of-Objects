/* 
 * File:   term.h
 * Purpose: Provide the declaration of the class named Term
 * Author: Pike
 *
 */

#ifndef TERM_H
#define	TERM_H

#include <string>

using namespace std;

class Term
{
   public:
    // default constructor
    Term();
    // initializes a term with the given query string and weight
    Term(string query, long weight);
    // compares the two terms in descending order by weight
    int byReverseWeightOrder(Term that);
    // compares the two terms in lexicographic order by query and queries are case-insensitive
    int compareTo(Term that);
    // compares the two terms in lexicographic order but using only the first r characters of each query
    // And prefix comparison is case-insensitive
    int byPrefixOrder(Term that, int r);
	friend bool operator>(const Term& T1, const Term& T2);
    friend ostream &operator<<(ostream &out, const Term &T);

   private:
    string query;
    long weight;
};

#endif	/* TERM_H */

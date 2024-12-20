/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:38:48 by cejin             #+#    #+#             */
/*   Updated: 2024/12/20 12:28:20 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"
#include <list>

/*
If you run it a first time with your MutantStack, and a second time replacing the
MutantStack with, for example, a std::list, the two outputs should be the same. Of
course, when testing another container, update the code below with the corresponding
member functions (push() can become push_back()).
*/

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }

void	mStack(void)
{
	MutantStack<int>			mstack;
	MutantStack<int>::iterator	it;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << "Push: 5\nPush: 17" << std::endl;
	std::cout << "top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "mstack.pop" << std::endl;

	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(0);
	std::cout << "Push: 3\nPush: 5\nPush: 737\nPush: 42\nPush: 0" << std::endl;

	it = mstack.begin();
	std::cout << "it: " << *it << std::endl;
	++it;
	std::cout << "it: " << *it << std::endl;
	--it;
	std::cout << "it: " << *it << std::endl;
	while (it != mstack.end())
	{
		std::cout << "it: " << *it << std::endl;
		it++;
	}
	std::cout << std::endl;
	while (it != mstack.begin())
	{
		it--;
		std::cout << "it: " << *it << std::endl;
	}
	std::stack<int> s(mstack);
}

void	mList(void)
{
	std::list<int>				mlist;
	std::list<int>::iterator	it;
	
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "Push: 5\nPush: 17" << std::endl;
	std::cout << "top: " << mlist.back() << std::endl;

	mlist.pop_back();
	std::cout << "mstack.pop_back" << std::endl;

	std::cout << "size: " << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(42);
	mlist.push_back(0);
	std::cout << "Push: 3\nPush: 5\nPush: 737\nPush: 42\nPush: 0" << std::endl;

	it = mlist.begin();
	std::cout << "it: " << *it << std::endl;
	++it;
	std::cout << "it: " << *it << std::endl;
	--it;
	std::cout << "it: " << *it << std::endl;
	while (it != mlist.end())
	{
		std::cout << "it: " << *it << std::endl;
		it++;
	}
	std::cout << std::endl;
	while (it != mlist.begin())
	{
		it--;
		std::cout << "it: " << *it << std::endl;
	}
	std::list<int> s(mlist);
}

int main()
{
	std::cout << CYAN "MutantStack" RESET << std::endl;
	mStack();
	std::cout << "==========================" << std::endl;
	std::cout << CYAN "List" RESET << std::endl;
	mList();
	return 0;
}

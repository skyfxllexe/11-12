#include <iostream>
#include <utility>
#include <vector>

template <class Iterator1, class Iterator2>
class postIterator
{
public:
    postIterator(Iterator1 it1, Iterator2 it2)
    {
    	it = make_pair(it1, it2);
    }

    std::pair<Iterator1, Iterator2> operator*() const
    {
    	return it;
    }

    postIterator &operator++() {
        ++(it.first);
        ++(it.second);
        return *this;
    }

   	postIterator operator++(int) {
   		postIterator temp = *this;
	    ++(*this);
	    return temp;
	}

    bool operator==(const postIterator &other) const {
        return it == other.it;
    }
    
    bool operator!=(const postIterator &other) const {
        return it != other.it;
    }

    bool operator < (const Iterator1 &other) const {
        return it.first < other;
    }
    
    bool operator > (const Iterator2 &other) const {
        return it.first > other.it.first;
    }
private:
	std::pair <Iterator1, Iterator2> it;
};


int main()
{
	std::vector <int> v1 {1, 2, 3, 4, 5};
	std::vector <int> v2 {6, 7, 8, 9, 10};
	std::vector<int>::iterator it1 = v1.begin();
	std::vector<int>::iterator it2 = v2.begin();
	for(postIterator pit = postIterator(it1, it2); pit < v1.end(); pit++)
	{
		std::cout << *((*pit).first) << " " << *((*pit).second) << std::endl;
	}

	return 0;
}
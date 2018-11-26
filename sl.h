#ifndef __SORTED_LIST_H__
#define __SORTED_LIST_H__

#include <list>
#include <functional>
#include <algorithm>
#include <iterator>

template<class T, class Comp = std::less<T> >
class SortedList {

    std::list<T> items;

    public:

        SortedList() {}

        template<class Iter>
        SortedList(Iter first, Iter last) : items(first, last) {
            items.sort(Comp());
        }

        void insert(const T& item) {
            items.insert(std::lower_bound(items.begin(), items.end(), item, Comp()), item);
        }

        int size() const {
            return items.size();
        }

        const T& front() const {
            return items.front();
        }

        const T& back() const {
            return items.back();
        }

        void remove(const T& item) {
            //items.remove(item);
            std::pair<typename std::list<T>::iterator, typename std::list<T>::iterator> range = std::equal_range(items.begin(), items.end(), item, Comp());
            items.erase(range.first, range.second);
        }

        typename std::list<T>::const_iterator begin() const {
            return items.begin();
        }

        typename std::list<T>::const_iterator end() const {
            return items.end();
        }
};

#endif
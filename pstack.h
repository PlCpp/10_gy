#ifndef __PSTACK__
#define __PSTACK__

#include <stack>
#include <map>

template<class T, class Prior = int, class Comp = std::less<Prior> >
class priority_stack {
    typedef std::map<Prior, std::stack<T>, Comp> PriorStack;

    PriorStack priorStack;

    public:
        
        void push(const Prior& prior, const T& item) {
            priorStack[prior].push(item);
        }

        int size(const Prior& prior) const {
            typename PriorStack::const_iterator it = priorStack.find(prior);
            if (it != priorStack.end()) {
                return it->second.size();
            }

            return 0;
        }

        int size() const {
            int ret = 0;
            for (typename PriorStack::const_iterator it = priorStack.begin(); it != priorStack.end(); ++it) {
                ret += it->second.size();
            }

            return ret;
        }

        const T& top() const {
            return priorStack.rbegin()->second.top();
        }

        T& top() {
            return priorStack.rbegin()->second.top();
        }

        void pop() {
            const Prior p = priorStack.rbegin()->first;
            priorStack.rbegin()->second.pop();
            if (priorStack.rbegin()->second.empty()) {
                priorStack.erase(p);
            }
        }
};

#endif
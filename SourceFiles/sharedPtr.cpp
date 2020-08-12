#include <iostream>
#include <string>

namespace smartPtr
{
    class counter
    {
    public:
        counter(const int cnt = 0): _count(cnt) {}
        int _count;
    };

    template<typename T>
    class shared_ptr
    {
    public:
        shared_ptr(T* p = 0): _ptr(p)
        {
            _cnt = new counter();
            if (p)  _cnt->_count = 1;
        }
        
        shared_ptr(const shared_ptr<T>& s_ptr)
        {
            _ptr = s_ptr._ptr;
            (s_ptr._cnt)->_count++;
            _cnt = s_ptr._cnt;
        }

        ~shared_ptr()
        {
           release();
        }

        shared_ptr& operator=(shared_ptr& other)
        {
            if (this == &other) return *this;

            release();

            ++(other._cnt)->_count;
            this->_cnt = other._cnt;
            this->_ptr = other._ptr;

            return *this;
        }

        int use_count() const
        {
            return _cnt->_count;
        }

        T* get()
        {
            return _ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        T* operator*()
        {
            return *_ptr;
        }

    protected:
        void release()
        {
            --(_cnt->_count);

            if (_cnt->_count < 1)
            {
                // std::cout << "smart delete" << std::endl;
                delete _ptr;
                _ptr = nullptr;
                delete _cnt;
                _cnt = nullptr;
            }
        }

    private:
        T* _ptr;
        counter* _cnt;
    };
}

int main()
{
    using namespace smartPtr;

    shared_ptr<std::string> pstr(new std::string("abc"));
    std::cout << pstr.use_count() << std::endl;

    shared_ptr<std::string> pstr2(pstr);
    std::cout << pstr.use_count() << std::endl;
    std::cout << pstr2.use_count() << std::endl;

    shared_ptr<std::string> pstr3(new std::string("cde"));
    std::cout << pstr3.use_count() << std::endl;

    pstr3 = pstr2;
    std::cout << pstr.use_count() << std::endl;
    std::cout << pstr2.use_count() << std::endl;
    std::cout << pstr3.use_count() << std::endl;

    return 0;
}
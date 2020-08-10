#pragma once

class Singleton
{
private:
    Singleton () {}
    Singleton (const Singleton&) {}
    Singleton& operator= (const Singleton&) {}
    
    // 成员变量
    static Singleton* m_instance;

public:
    ~Singleton () {}
    static Singleton* getInstance();
    void destory();
};

Singleton* Singleton::m_instance = nullptr;

Singleton* Singleton::getInstance()
{
    if (nullptr == m_instance)
    {
        m_instance = new Singleton();
    }

    return m_instance;
}

void Singleton::destory()
{
    if (nullptr != m_instance)
    {
        delete m_instance;
        m_instance = nullptr;
    }
}
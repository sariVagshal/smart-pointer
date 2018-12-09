#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__
#include <stdexcept>
template<typename T>
class UniquePtr
{
public:
    explicit UniquePtr(T*);
    ~UniquePtr();

    T* operator->() const;
    T& operator*()  const;

	UniquePtr& operator= (T* ptr);
	void reset();
	
	operator bool() const;
	
    T* get() const;

private:
    // Prevent copying 
    UniquePtr(UniquePtr const&);
    UniquePtr& operator=(UniquePtr const&);

    T*   m_ptr;
};

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr)
{
	m_ptr = ptr;
}

template<typename T>
UniquePtr<T>::~UniquePtr()
{
	delete m_ptr;
}

template<typename T>
T* UniquePtr<T>::operator->() const
{
	if (!m_ptr)
		throw std::invalid_argument::invalid_argument();
	return m_ptr;
}

template<typename T>
T& UniquePtr<T>::operator*()  const
{
	if (!m_ptr)
		throw std::invalid_argument::invalid_argument();
	return *m_ptr;
}

template<typename T>
UniquePtr<T>& operator= (T* ptr)
{
	delete m_ptr;
	m_ptr = ptr;
}

template<typename T>
void UniquePtr<T>::reset()
{
	m_ptr = NULL;
}

template<typename T>
UniquePtr<T>::operator bool() const
{
	return m_ptr;
}

template<typename T>
T* UniquePtr<T>::get() const
{
	return m_ptr;
}

#endif //__SMARTPTR_H__

#ifndef __SHAREDPTR_H__
#define __SHAREDPTR_H__
#include <stdexcept>

template<typename T>
class SharedPtr
{
public:
    explicit SharedPtr(T* = NULL);
    SharedPtr(const SharedPtr &);
    ~SharedPtr();

    T* operator->() const;
    T& operator*()  const;

	SharedPtr& operator= (T* ptr);
	void reset();
	
	bool operator!=(const SharedPtr&) const;
	bool operator==(const SharedPtr&) const;

	operator bool() const;
	
    T* get() const;	
	
	
private:
	T * m_ptr;
	size_t * refCount;
};

	
template<typename T>
SharedPtr<T>::SharedPtr(T* ptr)
{
	m_ptr = ptr;
	refCount = new size_t;
	*refCount = 1;
}

template<typename T>    
SharedPtr<T>::SharedPtr(const SharedPtr & sp)
{
	m_ptr = sp.m_ptr;
	refCount = sp.refCount;
	++(*refCount);
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
	if (*refCount == 1)
		delete m_ptr;
}

template<typename T>
T* SharedPtr<T>::operator->() const
{
	if (!m_ptr)
		throw std::invalid_argument::invalid_argument();
	return m_ptr;
}

template<typename T>
T& SharedPtr<T>::operator*()  const
{
	if (!m_ptr)
		throw std::invalid_argument::invalid_argument();
	return *m_ptr;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(T* ptr)
{
	--(*refCount);
	if(*refCount == 0)
		delete m_ptr;
	m_ptr = ptr.m_ptr;
	refCount = ptr.refCount;
	++(*refCount);
}

template<typename T>
void SharedPtr<T>::reset()
{
	delete m_ptr;
	m_ptr = NULL;
}
	
template<typename T>
bool SharedPtr<T>::operator!=(const SharedPtr& sp) const
{
	return m_ptr != sp.m_ptr;
}
	
template<typename T>
bool SharedPtr<T>::operator==(const SharedPtr& sp) const
{
	return m_ptr != sp.m_ptr;
}

template<typename T>
SharedPtr<T>::operator bool() const
{
	return m_ptr;
}

template<typename T>	
T* SharedPtr<T>::get() const
{
	return m_ptr;
}	
	
	
#enfif //__SHAREDPTR_H__

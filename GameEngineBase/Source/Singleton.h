#pragma once

namespace My
{
	namespace Pattern
	{
		template <typename Type>
		class Singleton;
	}
}
using My::Pattern::Singleton;

/**
* @brief 싱글턴 패턴
* @details 싱글턴 패턴을 구현한 클래스는 반드시 Singleton<Type>을 상속받아야 한다.
*
*/
template<typename Type>
class My::Pattern::Singleton
{
private:
	static Type* m_Instance;

public:
	static Type* GetInstancePtr()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new Type();
		}
		return m_Instance;
	}
	static Type& GetInstanceRef()
	{
		if (m_Instance == nullptr)
		{
			m_Instance = new Type();
		}
		return *m_Instance;
	}
	static void DestroyInstance()
	{
		if (m_Instance != nullptr)
		{
			delete m_Instance;
			m_Instance = nullptr;
		}
	}

private:
		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
		Singleton(Singleton&&) = delete;
		Singleton& operator=(Singleton&&) = delete;
protected:
		Singleton() 
		{
			if (nullptr != m_Instance)
			{
				m_Instance = nullptr;
			}
		};
		~Singleton() { DestroyInstance(); };
};

template<typename Type>
Type* Singleton<Type>::m_Instance = nullptr;
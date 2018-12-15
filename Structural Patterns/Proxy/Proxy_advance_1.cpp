/*
 * C++ Design Patterns: Proxy
 *
 * Proxy pattern provides a surrogate or placeholder for another object to control access to it.
 * The pattern has structural purpose and applies to objects.
 *
 */

#include<iostream>

/*
 * ### When to use ###
 *
 * whenever there is a need for a more versatile or sophisticated reference to an object than a simple pointer
 *
 */

// Real subject
class RealImage
{
public:
	RealImage(int i)
	{
		m_id = i;
		std::cout << "\t$$ ctor: " << m_id << std::endl;
	}
	~RealImage()
	{
		std::cout << "\tdtor: " << m_id << std::endl;
	}
	void draw()
	{
		std::cout << "\tdrawing image " << m_id << std::endl;
	}
	// ...

private:
	int m_id;
	// ...
};

// maintains a reference that lets the proxy access the real subject
#pragma region Proxy

class Image
{
public:
	Image()
	{
		m_id = s_next++;
		m_real_thing = nullptr;
	}
	~Image()
	{
		delete m_real_thing;
	}
	void draw()
	{
		if (m_real_thing == nullptr)
		{
			m_real_thing = new RealImage(m_id);
		}

		m_real_thing->draw();
	}
	// ...

private:
	RealImage * m_real_thing;
	int m_id;
	static int s_next;
	// ...
};

int Image::s_next = 1;

#pragma endregion


int main()
{
	Image images[5];

	for (int i; true;)
	{
		std::cout << "Exit[0], Image[1-5]: ";
		std::cin >> i;

		if (i == 0)
			break;

		images[i - 1].draw();
		// ...
	}

	return 0;
}

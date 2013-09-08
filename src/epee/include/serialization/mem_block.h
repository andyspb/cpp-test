// Copyright (c) 2006-2013, Andrey N. Sabelnikov, www.sabelnikov.net
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// * Neither the name of the Andrey N. Sabelnikov nor the
// names of its contributors may be used to endorse or promote products
// derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER  BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 


#ifndef _MEM_BLOCK_H_
#define _MEM_BLOCK_H_

/************************************************************************/
/*   mem_block_t                                                        */
/************************************************************************/
#include <malloc.h>

namespace epee
{
template<class free_method>
class mem_block_t
{
public:
	mem_block_t():m_ptr(NULL),m_size(0)
	{}	

	mem_block_t(const mem_block_t& block):m_ptr(NULL),m_size(0)
	{
		set(block);
	}	

	mem_block_t(const void* pbuff, size_t cb, bool b_attach = false):m_ptr(NULL),m_size(0)
	{
		if(!b_attach)
			set(pbuff, cb);//just copy
		else
			attach(const_cast<void*>(pbuff), cb);//attach
	}	


	virtual ~mem_block_t(){release();}	
	//operations
	virtual void* get(size_t* psize)
	{
		if(psize) *psize = m_size;
		return m_ptr;
	}

	virtual const void* get(size_t* psize) const
	{
		if(psize) *psize = m_size;
		return m_ptr;
	}

	virtual void set(const void * ptr, size_t cb)
	{
		if(!cb||!ptr) return;
		//optimize for same-size blocks
		if(cb == m_size)
			memcpy(m_ptr, ptr, m_size);
		else
		{
			release();
			if(ptr)
			{
				m_ptr = free_method::alloc_t(cb);
				m_size = cb;
				memcpy(m_ptr, ptr, m_size);
			}
		}
	}
	 
	virtual void set(const mem_block_t& block)
	{
		size_t cb = 0;
		const void* ptr = block.get(&cb);
		set(ptr, cb);
	}

	mem_block_t& operator=(const mem_block_t& block)
	{
		set(block);
		return *this;
	}

	virtual void* alloc_buff(size_t cb)
	{
		release();
		m_ptr = free_method::alloc_t(cb);
		m_size = cb;
		return m_ptr;
	}
	virtual void release()
	{
		if(m_ptr) free_method::free_t(m_ptr);
	}

	void attach(void* pbuf, size_t cb)
	{
		release();
		m_ptr = pbuf;
		m_size = cb;
	}

	void* detach(size_t* psize)
	{
		void *ptr = m_ptr;
		if(psize) *psize = m_size;
		release();
		return ptr;
	}
	size_t get_size() const
	{
		return m_size;
	}


protected:
	void*  m_ptr;
	size_t m_size;
};

/************************************************************************/
/*   free_via_crtfree													*/
/*	 free_via_delete													*/
/************************************************************************/

struct free_via_crtfree
{
	static void  free_t(void* ptr)  {::free(ptr);}
	static void* alloc_t(size_t cb) {return ::malloc(cb);}
};

struct free_via_delete 
{
	static void  free_t(void* ptr) { delete (char*)ptr;  }
	static void* alloc_t(size_t cb){ return (void*) new char[cb];}
};

typedef mem_block_t<free_via_delete>  mem_block;
typedef mem_block_t<free_via_crtfree> mem_block_crt;

typedef mem_block CMemoryObject; //just a big-letter redefinition



//alwas attaches to buffer and do not free memory when deleting
class fake_mem_block: public mem_block
{
public:
	fake_mem_block(const void * ptr, size_t cb):mem_block(ptr, cb, true)
	{}
	fake_mem_block(volatile const void * ptr, size_t cb):mem_block((const void *)ptr, cb, true)
	{}
	virtual ~fake_mem_block()
	{
		m_ptr = NULL;//to avoid free in mem_block::~mem_block()
	}
	virtual void release(){}

};
}
#endif //_MEM_BLOCK_H_

/*
 * Copyright (c) 2012-2014, Seong il Shin <hanael80 at gmail dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#pragma once


#include <deque>
#include <list>
#include <map>
#include <set>
#include <vector>


struct ForEachBaseIterator
{
	inline operator bool() const
	{
		return true;
	}
};

template< typename T >
struct ForEachContainerIterator
	:
	ForEachBaseIterator
{
	typename T::const_iterator m_cur;

	ForEachContainerIterator( T& v )
	:
	m_cur( v.begin() )
	{
	}
};

template< typename T >
struct ForEachContainerReverseIterator
	:
	ForEachBaseIterator
{
	typename T::const_reverse_iterator m_cur;

	ForEachContainerReverseIterator( T& v )
	:
	m_cur( v.rbegin() )
	{
	}
};

template< typename T >
struct ForEachArrayIterator
	:
	ForEachBaseIterator
{
	T* m_cur;

	ForEachArrayIterator( T* s )
	:
	m_cur( s )
	{
	}
};

template< typename T >
inline ForEachContainerIterator< std::list< T > > ForEach_GetIterator( const std::list< T >& v )
{
	return ForEachContainerIterator< std::list< T > >( (std::list< T >&)( v ) );
}

template< typename T >
inline ForEachContainerReverseIterator< std::list< T > > ForEach_GetReverseIterator( const std::list< T >& v, unsigned int )
{
	return ForEachContainerReverseIterator< std::list< T > >( (std::list< T >&)( v ) );
}

template< typename T >
inline unsigned int ForEach_GetSize( const std::list< T >& v, unsigned int )
{
	return (unsigned int)( v.size() );
}

template< typename T >
inline T& ForEach_FetchElement( ForEachBaseIterator const & iter, std::list< T >& )
{
	typedef ForEachContainerIterator< std::list< T > > IteratorType;

	T& v = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename T >
inline T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, std::list< T >& )
{
	typedef ForEachContainerReverseIterator< std::list< T > > IteratorType;

	T& v = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename T >
inline const T& ForEach_FetchElement( ForEachBaseIterator const & iter, const std::list< T >& )
{
	typedef ForEachContainerIterator< std::list< T > > IteratorType;

	T& v = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename T >
inline const T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const std::list< T >& )
{
	typedef ForEachContainerReverseIterator< std::list< T > > IteratorType;

	T& v = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename T >
inline ForEachContainerIterator< std::deque< T > > ForEach_GetIterator( const std::deque< T >& v )
{
	return ForEachContainerIterator< std::deque< T > >( (std::deque< T >&)( v ) );
}

template< typename T >
inline ForEachContainerReverseIterator< std::deque< T > > ForEach_GetReverseIterator( const std::deque< T >& v, unsigned int )
{
	return ForEachContainerReverseIterator< std::deque< T > >( (std::deque< T >&)( v ) );
}

template< typename T >
inline unsigned int ForEach_GetSize( const std::deque< T >& v, unsigned int )
{
	return (unsigned int)( v.size() );
}

template< typename T >
inline T& ForEach_FetchElement( ForEachBaseIterator const & iter, std::deque< T >& )
{
	typedef ForEachContainerIterator< std::deque< T > > IteratorType;

	T& v = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename T >
inline T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, std::deque< T >& )
{
	typedef ForEachContainerReverseIterator< std::deque< T > > IteratorType;

	T& v = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename T >
inline const T& ForEach_FetchElement( ForEachBaseIterator const & iter, const std::deque< T >& )
{
	typedef ForEachContainerIterator< std::deque< T > > IteratorType;

	T& v = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename T >
inline const T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const std::deque< T >& )
{
	typedef ForEachContainerReverseIterator< std::deque< T > > IteratorType;

	T& v = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename Key, typename Value >
inline ForEachContainerIterator< std::map< Key, Value > > ForEach_GetIterator( const std::map< Key, Value >& v )
{
	return ForEachContainerIterator< std::map< Key, Value > >( (std::map< Key, Value >&)( v ) );
}

template< typename Key, typename Value >
inline ForEachContainerReverseIterator< std::map< Key, Value > > ForEach_GetReverseIterator( const std::map< Key, Value >& v, unsigned int )
{
	return ForEachContainerReverseIterator< std::map< Key, Value > >( (std::map< Key, Value >&)( v ) );
}

template< typename Key, typename Value >
inline unsigned int ForEach_GetSize( const std::map< Key, Value >& v, unsigned int )
{
	return (unsigned int)( v.size() );
}

template< typename Key, typename Value >
inline typename std::map< Key, Value >::value_type& ForEach_GetElement( ForEachBaseIterator const & iter, std::map< Key, Value >& )
{
	typedef ForEachContainerIterator< std::map< Key, Value > > IteratorType;

	return (typename std::map< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
}

template< typename Key, typename Value >
inline const typename std::map< Key, Value >::value_type& ForEach_GetElement( ForEachBaseIterator const & iter, const std::map< Key, Value >& )
{
	typedef ForEachContainerIterator< std::map< Key, Value > > IteratorType;

	return ( *((IteratorType&)( iter )).m_cur );
}

template< typename Key, typename Value >
inline typename std::map< Key, Value >::value_type& ForEach_GetReverseElement( ForEachBaseIterator const & iter, std::map< Key, Value >& )
{
	typedef ForEachContainerReverseIterator< std::map< Key, Value > > IteratorType;

	return (typename std::map< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
}

template< typename Key, typename Value >
inline const typename std::map< Key, Value >::value_type& ForEach_GetReverseElement( ForEachBaseIterator const & iter, const std::map< Key, Value >& )
{
	typedef ForEachContainerReverseIterator< std::map< Key, Value > > IteratorType;

	return ( *((IteratorType&)( iter )).m_cur );
}

template< typename Key, typename Value >
inline typename std::map< Key, Value >::value_type& ForEach_FetchElement( ForEachBaseIterator const & iter, std::map< Key, Value >& )
{
	typedef ForEachContainerIterator< std::map< Key, Value > > IteratorType;

	typename std::map< Key, Value >::value_type& v = (typename std::map< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename Key, typename Value >
inline typename std::map< Key, Value >::value_type& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, std::map< Key, Value >& )
{
	typedef ForEachContainerReverseIterator< std::map< Key, Value > > IteratorType;

	typename std::map< Key, Value >::value_type& v = (typename std::map< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename Key, typename Value >
inline const typename std::map< Key, Value >::value_type& ForEach_FetchElement( ForEachBaseIterator const & iter, const std::map< Key, Value >& )
{
	typedef ForEachContainerIterator< std::map< Key, Value > > IteratorType;

	typename std::map< Key, Value >::value_type& v = (typename std::map< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename Key, typename Value >
inline const typename std::map< Key, Value >::value_type& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const std::map< Key, Value >& )
{
	typedef ForEachContainerReverseIterator< std::map< Key, Value > > IteratorType;

	typename std::map< Key, Value >::value_type& v = (typename std::map< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename Key, typename Value >
inline ForEachContainerIterator< std::multimap< Key, Value > > ForEach_GetIterator( const std::multimap< Key, Value >& v )
{
	return ForEachContainerIterator< std::multimap< Key, Value > >( (std::multimap< Key, Value >&)( v ) );
}

template< typename Key, typename Value >
inline ForEachContainerReverseIterator< std::multimap< Key, Value > > ForEach_GetReverseIterator( const std::multimap< Key, Value >& v, unsigned int )
{
	return ForEachContainerReverseIterator< std::multimap< Key, Value > >( (std::multimap< Key, Value >&)( v ) );
}

template< typename Key, typename Value >
inline unsigned int ForEach_GetSize( const std::multimap< Key, Value >& v, unsigned int )
{
	return (unsigned int)( v.size() );
}

template< typename Key, typename Value >
inline typename std::multimap< Key, Value >::value_type& ForEach_GetElement( ForEachBaseIterator const & iter, std::multimap< Key, Value >& )
{
	typedef ForEachContainerIterator< std::multimap< Key, Value > > IteratorType;

	return (typename std::multimap< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
}

template< typename Key, typename Value >
inline const typename std::multimap< Key, Value >::value_type& ForEach_GetElement( ForEachBaseIterator const & iter, const std::multimap< Key, Value >& )
{
	typedef ForEachContainerIterator< std::multimap< Key, Value > > IteratorType;

	return ( *((IteratorType&)( iter )).m_cur );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template< typename Key, typename Value >
inline typename std::multimap< Key, Value >::value_type& ForEach_FetchElement( ForEachBaseIterator const & iter, std::multimap< Key, Value >& )
{
	typedef ForEachContainerIterator< std::multimap< Key, Value > > IteratorType;

	typename std::multimap< Key, Value >::value_type& v = (typename std::multimap< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename Key, typename Value >
inline typename std::multimap< Key, Value >::value_type& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, std::multimap< Key, Value >& )
{
	typedef ForEachContainerReverseIterator< std::multimap< Key, Value > > IteratorType;

	typename std::multimap< Key, Value >::value_type& v = (typename std::multimap< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename Key, typename Value >
inline const typename std::multimap< Key, Value >::value_type& ForEach_FetchElement( ForEachBaseIterator const & iter, const std::multimap< Key, Value >& )
{
	typedef ForEachContainerIterator< std::multimap< Key, Value > > IteratorType;

	typename std::multimap< Key, Value >::value_type& v = (typename std::multimap< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename Key, typename Value >
inline const typename std::multimap< Key, Value >::value_type& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const std::multimap< Key, Value >& )
{
	typedef ForEachContainerReverseIterator< std::multimap< Key, Value > > IteratorType;

	typename std::multimap< Key, Value >::value_type& v = (typename std::multimap< Key, Value >::value_type&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return v;
}

template< typename T >
inline ForEachContainerIterator< std::set< T > > ForEach_GetIterator( const std::set< T >& v )
{
	return ForEachContainerIterator< std::set< T > >( (std::set< T >&)( v ) );
}

template< typename T >
inline ForEachContainerReverseIterator< std::set< T > > ForEach_GetReverseIterator( const std::set< T >& v, unsigned int )
{
	return ForEachContainerReverseIterator< std::set< T > >( (std::set< T >&)( v ) );
}

template< typename T >
inline unsigned int ForEach_GetSize( const std::set< T >& v, unsigned int )
{
	return (unsigned int)( v.size() );
}

template< typename T >
inline T& ForEach_FetchElement( ForEachBaseIterator const & iter, std::set< T >& v )
{
	typedef ForEachContainerIterator< std::set< T > > IteratorType;

	T& e = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return e;
}

template< typename T >
inline T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, std::set< T >& v )
{
	typedef ForEachContainerReverseIterator< std::set< T > > IteratorType;

	T& e = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return e;
}

template< typename T >
inline const T& ForEach_FetchElement( ForEachBaseIterator const & iter, const std::set< T >& v )
{
	typedef ForEachContainerIterator< std::set< T > > IteratorType;

	T& e = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return e;
}

template< typename T >
inline const T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const std::set< T >& v )
{
	typedef ForEachContainerReverseIterator< std::set< T > > IteratorType;

	T& e = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return e;
}

template< typename T >
inline ForEachContainerIterator< std::multiset< T > > ForEach_GetIterator( const std::multiset< T >& v )
{
	return ForEachContainerIterator< std::multiset< T > >( (std::multiset< T >&)( v ) );
}

template< typename T >
inline ForEachContainerReverseIterator< std::multiset< T > > ForEach_GetReverseIterator( const std::multiset< T >& v, unsigned int )
{
	return ForEachContainerReverseIterator< std::multiset< T > >( (std::multiset< T >&)( v ) );
}

template< typename T >
inline unsigned int ForEach_GetSize( const std::multiset< T >& v, unsigned int )
{
	return (unsigned int)( v.size() );
}

template< typename T >
inline T& ForEach_FetchElement( ForEachBaseIterator const & iter, std::multiset< T >& v )
{
	typedef ForEachContainerIterator< std::multiset< T > > IteratorType;

	T& e = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return e;
}

template< typename T >
inline T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, std::multiset< T >& v )
{
	typedef ForEachContainerReverseIterator< std::multiset< T > > IteratorType;

	T& e = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return e;
}

template< typename T >
inline const T& ForEach_FetchElement( ForEachBaseIterator const & iter, const std::multiset< T >& v )
{
	typedef ForEachContainerIterator< std::multiset< T > > IteratorType;

	T& e = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return e;
}

template< typename T >
inline const T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const std::multiset< T >& v )
{
	typedef ForEachContainerReverseIterator< std::multiset< T > > IteratorType;

	T& e = (T&)( *((IteratorType&)( iter )).m_cur );
	++((IteratorType&)( iter )).m_cur;

	return e;
}

template< typename T >
inline ForEachArrayIterator< T > ForEach_GetIterator( const std::vector< T >& v )
{
	return ForEachArrayIterator< T >( (T*)( &v[ 0 ] ) );
}

template< typename T >
inline ForEachArrayIterator< T > ForEach_GetReverseIterator( const std::vector< T >& v, unsigned int )
{
	return ForEachArrayIterator< T >( (T*)( &v[ v.size() - 1 ] ) );
}

template< typename T >
inline unsigned int ForEach_GetSize( const std::vector< T >& v, unsigned int )
{
	return (unsigned int)( v.size() );
}

template< typename T >
inline T& ForEach_FetchElement( ForEachBaseIterator const & iter, std::vector< T >& v )
{
	return *((ForEachArrayIterator< T >&)( iter )).m_cur++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template< typename T >
inline T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, std::vector< T >& v )
{
	return *((ForEachArrayIterator< T >&)( iter )).m_cur--;
}

template< typename T >
inline const T& ForEach_FetchElement( ForEachBaseIterator const & iter, const std::vector< T >& v )
{
	return *((ForEachArrayIterator< T >&)( iter )).m_cur++;
}

template< typename T >
inline const T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const std::vector< T >& v )
{
	return *((ForEachArrayIterator< T >&)( iter )).m_cur--;
}

inline ForEachArrayIterator< char > ForEach_GetIterator( const std::string& v )
{
	return ForEachArrayIterator< char >( const_cast< char* >( reinterpret_cast< const char* >( &v[ 0 ] ) ) );
}

inline ForEachArrayIterator< char > ForEach_GetReverseIterator( const std::string& v, unsigned int )
{
	return ForEachArrayIterator< char >( const_cast< char* >( reinterpret_cast< const char* >( &v[ v.size() - 1 ] ) ) );
}

inline unsigned int ForEach_GetSize( const std::string& v, unsigned int )
{
	return (unsigned int)( v.size() );
}

inline char& ForEach_FetchElement( ForEachBaseIterator const & iter, std::string& v )
{
	return *((ForEachArrayIterator< char >&)( iter )).m_cur++;
}

inline char& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, std::string& v )
{
	return *((ForEachArrayIterator< char >&)( iter )).m_cur--;
}

inline const char& ForEach_FetchElement( ForEachBaseIterator const & iter, const std::string& v )
{
	return *((ForEachArrayIterator< char >&)( iter )).m_cur++;
}

inline const char& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const std::string& v )
{
	return *((ForEachArrayIterator< char >&)( iter )).m_cur--;
}

template< typename T >
inline ForEachArrayIterator< T >& ForEach_GetIterator( const T v[] )
{
	return ForEachArrayIterator< T >( (T*)( &v[ 0 ] ) );
}

template< typename T >
inline ForEachArrayIterator< T >& ForEach_GetReverseIterator( const T v[], unsigned int size )
{
	return ForEachArrayIterator< T >( (T*)( &v[ size / sizeof( T ) ] ) );
}

template< typename T >
inline unsigned int ForEach_GetSize( const T v[], unsigned int size )
{
	return size / sizeof( T );
}

template< typename T >
inline T& ForEach_FetchElement( ForEachBaseIterator const & iter, T v[] )
{
	return *((ForEachArrayIterator< T >&)( iter )).m_cur++;
}

template< typename T >
inline T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, T v[] )
{
	return *((ForEachArrayIterator< T >&)( iter )).m_cur--;
}

template< typename T >
inline const T& ForEach_FetchElement( ForEachBaseIterator const & iter, const T v[] )
{
	return *((ForEachArrayIterator< T >&)( iter )).m_cur++;
}

template< typename T >
inline const T& ForEach_ReverseFetchElement( ForEachBaseIterator const & iter, const T v[] )
{
	return *((ForEachArrayIterator< T >&)( iter )).m_cur--;
}

#define _DECLARE_FOREACH_VAR_NAME_2( name, line ) name ## line
#define _DECLARE_FOREACH_VAR_NAME_1( name, line ) _DECLARE_FOREACH_VAR_NAME_2( name, line )
#define _FOREACH_V( name ) _DECLARE_FOREACH_VAR_NAME_1( name, __LINE__ )

#define for_each( var, con )                                                                                                          \
	if ( unsigned int _FOREACH_V( size ) = ForEach_GetSize( con, sizeof( con ) ) )                                                    \
		if ( ForEachBaseIterator const & _FOREACH_V( iter ) = ForEach_GetIterator( con ) )                                            \
			if ( bool _FOREACH_V( loop ) = true )                                                                                     \
				while ( _FOREACH_V( size )-- && _FOREACH_V( loop ) )                                                                  \
					if ( (_FOREACH_V( loop ) = false) ) {} else                                                                       \
						for ( var = ForEach_FetchElement( _FOREACH_V( iter ), con ); !_FOREACH_V( loop ); _FOREACH_V( loop ) = true )

#define for_each_map( key, val, con )                                                                                                            \
	if ( unsigned int _FOREACH_V( size ) = ForEach_GetSize( con, sizeof( con ) ) )                                                               \
		if ( ForEachBaseIterator const & _FOREACH_V( iter ) = ForEach_GetIterator( con ) )                                                       \
			if ( bool _FOREACH_V( loop ) = true )                                                                                                \
				while ( _FOREACH_V( size )-- && _FOREACH_V( loop ) )                                                                             \
					if ( (_FOREACH_V( loop ) = false) ) {} else if ( unsigned int _FOREACH_V( loop2 ) = 1 )                                      \
						for ( key = ForEach_GetElement( _FOREACH_V( iter ), con ).first; _FOREACH_V( loop2 )--; )                                \
							for ( val = ForEach_FetchElement( _FOREACH_V( iter ), con ).second; !_FOREACH_V( loop ); _FOREACH_V( loop ) = true )

#define for_each_map_key( key, con )                                                                                                        \
	if ( unsigned int _FOREACH_V( size ) = ForEach_GetSize( con, sizeof( con ) ) )                                                          \
		if ( ForEachBaseIterator const & _FOREACH_V( iter ) = ForEach_GetIterator( con ) )                                                  \
			if ( bool _FOREACH_V( loop ) = true )                                                                                           \
				while ( _FOREACH_V( size )-- && _FOREACH_V( loop ) )                                                                        \
					if ( (_FOREACH_V( loop ) = false) ) {} else                                                                             \
						for ( key = ForEach_FetchElement( _FOREACH_V( iter ), con ).first; !_FOREACH_V( loop ); _FOREACH_V( loop ) = true )

#define for_each_map_value( val, con )                                                                                                       \
	if ( unsigned int _FOREACH_V( size ) = ForEach_GetSize( con, sizeof( con ) ) )                                                           \
		if ( ForEachBaseIterator const & _FOREACH_V( iter ) = ForEach_GetIterator( con ) )                                                   \
			if ( bool _FOREACH_V( loop ) = true )                                                                                            \
				while ( _FOREACH_V( size )-- && _FOREACH_V( loop ) )                                                                         \
					if ( (_FOREACH_V( loop ) = false) ) {} else                                                                              \
						for ( val = ForEach_FetchElement( _FOREACH_V( iter ), con ).second; !_FOREACH_V( loop ); _FOREACH_V( loop ) = true )

#define for_each_r( var, con )                                                                                                               \
	if ( unsigned int _FOREACH_V( size ) = ForEach_GetSize( con, sizeof( con ) ) )                                                           \
		if ( ForEachBaseIterator const & _FOREACH_V( iter ) = ForEach_GetReverseIterator( con, sizeof( con ) ) )                             \
			if ( bool _FOREACH_V( loop ) = true )                                                                                            \
				while ( _FOREACH_V( size )-- && _FOREACH_V( loop ) )                                                                         \
					if ( (_FOREACH_V( loop ) = false) ) {} else                                                                              \
						for ( var = ForEach_ReverseFetchElement( _FOREACH_V( iter ), con ); !_FOREACH_V( loop ); _FOREACH_V( loop ) = true )

#define for_each_map_r( key, val, con )                                                                                                                 \
	if ( unsigned int _FOREACH_V( size ) = ForEach_GetSize( con, sizeof( con ) ) )                                                                      \
		if ( ForEachBaseIterator const & _FOREACH_V( iter ) = ForEach_GetReverseIterator( con, sizeof( con ) ) )                                        \
			if ( bool _FOREACH_V( loop ) = true )                                                                                                       \
				while ( _FOREACH_V( size )-- && _FOREACH_V( loop ) )                                                                                    \
					if ( (_FOREACH_V( loop ) = false) ) {} else if ( unsigned int _FOREACH_V( loop2 ) = 1 )                                             \
						for ( key = ForEach_GetReverseElement( _FOREACH_V( iter ), con ).first; _FOREACH_V( loop2 )--; )                                \
							for ( val = ForEach_ReverseFetchElement( _FOREACH_V( iter ), con ).second; !_FOREACH_V( loop ); _FOREACH_V( loop ) = true )

#define for_each_map_key_r( key, con )                                                                                                             \
	if ( unsigned int _FOREACH_V( size ) = ForEach_GetSize( con, sizeof( con ) ) )                                                                 \
		if ( ForEachBaseIterator const & _FOREACH_V( iter ) = ForEach_GetReverseIterator( con, sizeof( con ) ) )                                   \
			if ( bool _FOREACH_V( loop ) = true )                                                                                                  \
				while ( _FOREACH_V( size )-- && _FOREACH_V( loop ) )                                                                               \
					if ( (_FOREACH_V( loop ) = false) ) {} else                                                                                    \
						for ( key = ForEach_ReverseFetchElement( _FOREACH_V( iter ), con ).first; !_FOREACH_V( loop ); _FOREACH_V( loop ) = true )

#define for_each_map_value_r( val, con )                                                                                                            \
	if ( unsigned int _FOREACH_V( size ) = ForEach_GetSize( con, sizeof( con ) ) )                                                                  \
		if ( ForEachBaseIterator const & _FOREACH_V( iter ) = ForEach_GetReverseIterator( con, sizeof( con ) ) )                                    \
			if ( bool _FOREACH_V( loop ) = true )                                                                                                   \
				while ( _FOREACH_V( size )-- && _FOREACH_V( loop ) )                                                                                \
					if ( (_FOREACH_V( loop ) = false) ) {} else                                                                                     \
						for ( val = ForEach_ReverseFetchElement( _FOREACH_V( iter ), con ).second; !_FOREACH_V( loop ); _FOREACH_V( loop ) = true )

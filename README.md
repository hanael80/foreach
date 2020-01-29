foreach
=======

fast foreach for c++ stl containers and array

you can use on windows, linux, android ndk, objective-c


example:
```cpp
	std::vector< int > v;
	v.push_back( 1 );
	v.push_back( 2 );
	v.push_back( 3 );
	for_each( int i, v )
		printf( "%d\n", i );

	// reserve interate
	for_each_r( int i, v )
		printf( "%d\n", i );

	std::map< int, int > m;
	m[ 1 ] = 2;
	m[ 3 ] = 1;
	
	// iterate key & value
	for_each_map( int key, int value, m )
		printf( "%d, %d\n", key, value );

	// iterate only value
	for_each_map_value( int value, m )
		printf( "%d\n", value );
```

foreach
=======

fast foreach for c++ stl containers and array

this can be used on windows, linux, android ndk, objective-c


example:

	std::vector< int > v;
	v.push_back( 1 );
	v.push_back( 2 );
	v.push_back( 3 );
	for_each( int i, v )
		printf( "%d\n", i );

	for_each_r( int i, v )
		printf( "%d\n", i );

	std::map< int, int > m;
	m[ 1 ] = 2;
	m[ 3 ] = 1;
	for_each_map( int key, int value, m )
		printf( "%d, %d\n", key, value );

	for_each_map_value( int value, m )
		printf( "%d\n", value );

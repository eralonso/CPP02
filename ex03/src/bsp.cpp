#include	"Point.hpp"

Point	cross_product( const Point& o, const Point& p1, const Point& p2)
{
	float	x;
	float	y;
	float	z;

	x = ( ( ( p1.getY() - o.getY() ) * ( p2.getZ() - o.getZ() ) ) - \
	    ( ( p1.getZ() - o.getZ() ) * ( p2.getY() - o.getY() ) ) ).toFloat();
	y = ( ( ( p1.getZ() - o.getZ() ) * ( p2.getX() - o.getX() ) ) - \
	    ( ( p1.getX() - o.getX() ) * ( p2.getZ() - o.getZ() ) ) ).toFloat();
	z = ( ( ( p1.getX() - o.getX() ) * ( p2.getY() - o.getY() ) ) - \
	    ( ( p1.getY() - o.getY() ) * ( p2.getX() - o.getX() ) ) ).toFloat();
	return (Point(x, y, z));
}

bool	bsp( const Point a, const Point b, const Point c, const Point p )
{
	Point	pab;
	Point	pbc;
	Point	pca;

	if (a == p || b == p || c == p || a == b || c == b || a == c)
		return (false);
	pab = cross_product( p, a, b );	
	pbc = cross_product( p, b, c );	
	pca = cross_product( p, c, a );	
	if (pab.getZ().toFloat() == 0 || pbc.getZ().toFloat() == 0 || pca.getZ().toFloat() == 0)
		return (false);
	return ( ( pab.getZ().toFloat() > 0 && pbc.getZ().toFloat() > 0 && pca.getZ().toFloat() > 0 ) \
		|| ( pab.getZ().toFloat() < 0 && pbc.getZ().toFloat() < 0 && pca.getZ().toFloat() < 0 ) );
}

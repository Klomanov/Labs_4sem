#include <gmsh.h>
#include <set>
#include <vector>

void build_torus(double x, double y, double z, double rad1, double rad2) {
	double lc = 1e-1;

	int p1 = gmsh::model::geo::addPoint(x, y, z, lc);
	int p2 = gmsh::model::geo::addPoint(x + rad1, y, z, lc);
	int p3 = gmsh::model::geo::addPoint(x, y + rad1, z, lc);
	int p4 = gmsh::model::geo::addPoint(x - rad1, y, z, lc);
	int p5 = gmsh::model::geo::addPoint(x, y - rad1, z, lc);

	int p6 = gmsh::model::geo::addPoint(x, y, 2 * rad2 + z, lc);
	int p7 = gmsh::model::geo::addPoint(x + rad1, y, 2 * rad2 + z, lc);
	int p8 = gmsh::model::geo::addPoint(x, y + rad1, 2 * rad2 + z, lc);
	int p9 = gmsh::model::geo::addPoint(x - rad1, y, 2 * rad2 + z, lc);
	int p10 = gmsh::model::geo::addPoint(x, y - rad1, 2 * rad2 + z, lc);

	int p11 = gmsh::model::geo::addPoint(x - rad1, y, z + rad2, lc);
	int p12 = gmsh::model::geo::addPoint(x - rad1 + rad2, y, z + rad2, lc);
	int p13 = gmsh::model::geo::addPoint(x - rad1 - rad2, y, z + rad2, lc);

	int p14 = gmsh::model::geo::addPoint(x + rad1, y, z + rad2, lc);
	int p15 = gmsh::model::geo::addPoint(x + rad1 + rad2, y, z + rad2, lc);
	int p16 = gmsh::model::geo::addPoint(x + rad1 - rad2, y, z + rad2, lc);

	int p17 = gmsh::model::geo::addPoint(x, y + rad1, z + rad2, lc);
	int p18 = gmsh::model::geo::addPoint(x, y + rad1 + rad2, z + rad2, lc);
	int p19 = gmsh::model::geo::addPoint(x, y + rad1 - rad2, z + rad2, lc);

	int p20 = gmsh::model::geo::addPoint(x, y - rad1, z + rad2, lc);
	int p21 = gmsh::model::geo::addPoint(x, y - rad1 + rad2, z + rad2, lc);
	int p22 = gmsh::model::geo::addPoint(x, y - rad1 - rad2, z + rad2, lc);

	int p23 = gmsh::model::geo::addPoint(x, y, z + rad2, lc);

	int a1 = gmsh::model::geo::addCircleArc(p4, p1, p3);
	int a2 = gmsh::model::geo::addCircleArc(p3, p1, p2);
	int a3 = gmsh::model::geo::addCircleArc(p2, p1, p5);
	int a4 = gmsh::model::geo::addCircleArc(p5, p1, p4);

	int a5 = gmsh::model::geo::addCircleArc(p9, p6, p8);
	int a6 = gmsh::model::geo::addCircleArc(p8, p6, p7);
	int a7 = gmsh::model::geo::addCircleArc(p7, p6, p10);
	int a8 = gmsh::model::geo::addCircleArc(p10, p6, p9);

	int a9 = gmsh::model::geo::addCircleArc(p12, p11, p4);
	int a10 = gmsh::model::geo::addCircleArc(p4, p11, p13);
	int a11 = gmsh::model::geo::addCircleArc(p13, p11, p9);
	int a12 = gmsh::model::geo::addCircleArc(p9, p11, p12);

	int a13 = gmsh::model::geo::addCircleArc(p7, p14, p15);
	int a14 = gmsh::model::geo::addCircleArc(p15, p14, p2);
	int a15 = gmsh::model::geo::addCircleArc(p2, p14, p16);
	int a16 = gmsh::model::geo::addCircleArc(p16, p14, p7);

	int a17 = gmsh::model::geo::addCircleArc(p8, p17, p19);
	int a18 = gmsh::model::geo::addCircleArc(p19, p17, p3);
	int a19 = gmsh::model::geo::addCircleArc(p3, p17, p18);
	int a20 = gmsh::model::geo::addCircleArc(p18, p17, p8);

	int a21 = gmsh::model::geo::addCircleArc(p10, p20, p22);
	int a22 = gmsh::model::geo::addCircleArc(p22, p20, p5);
	int a23 = gmsh::model::geo::addCircleArc(p5, p20, p21);
	int a24 = gmsh::model::geo::addCircleArc(p21, p20, p10);

	int a25 = gmsh::model::geo::addCircleArc(p13, p23, p22);
	int a26 = gmsh::model::geo::addCircleArc(p22, p23, p15);
	int a27 = gmsh::model::geo::addCircleArc(p15, p23, p18);
	int a28 = gmsh::model::geo::addCircleArc(p18, p23, p13);

	int a29 = gmsh::model::geo::addCircleArc(p21, p23, p12);
	int a30 = gmsh::model::geo::addCircleArc(p12, p23, p19);
	int a31 = gmsh::model::geo::addCircleArc(p19, p23, p16);
	int a32 = gmsh::model::geo::addCircleArc(p16, p23, p21);

	int c1 = gmsh::model::geo::addCurveLoop({ a20, -a5, -a11, -a28 });
	int s1 = gmsh::model::geo::addSurfaceFilling({ c1 });

	int c2 = gmsh::model::geo::addCurveLoop({ -a13, -a6, -a20, -a27 });
	int s2 = gmsh::model::geo::addSurfaceFilling({ c2 });

	int c3 = gmsh::model::geo::addCurveLoop({ a11, -a8, a21, -a25 });
	int s3 = gmsh::model::geo::addSurfaceFilling({ c3 });

	int c4 = gmsh::model::geo::addCurveLoop({ -a21, -a7, a13, -a26 });
	int s4 = gmsh::model::geo::addSurfaceFilling({ c4 });

	int c5 = gmsh::model::geo::addCurveLoop({ -a12, a5, a17, -a30 });
	int s5 = gmsh::model::geo::addSurfaceFilling({ c5 });

	int c6 = gmsh::model::geo::addCurveLoop({ -a17, a6, -a16, -a31 });
	int s6 = gmsh::model::geo::addSurfaceFilling({ c6 });

	int c7 = gmsh::model::geo::addCurveLoop({ a16, a7, -a24, -a32 });
	int s7 = gmsh::model::geo::addSurfaceFilling({ c7 });

	int c8 = gmsh::model::geo::addCurveLoop({ a24, a8, a12, -a29 });
	int s8 = gmsh::model::geo::addSurfaceFilling({ c8 });

	int c9 = gmsh::model::geo::addCurveLoop({ -a22, a26, a14, a3 });
	int s9 = gmsh::model::geo::addSurfaceFilling({ c9 });

	int c10 = gmsh::model::geo::addCurveLoop({ -a14, a27, -a19, a2 });
	int s10 = gmsh::model::geo::addSurfaceFilling({ c10 });

	int c11 = gmsh::model::geo::addCurveLoop({ a19, a28, -a10, a1 });
	int s11 = gmsh::model::geo::addSurfaceFilling({ c11 });

	int c12 = gmsh::model::geo::addCurveLoop({ a10, a25, a22, a4 });
	int s12 = gmsh::model::geo::addSurfaceFilling({ c12 });

	int c13 = gmsh::model::geo::addCurveLoop({ a23, a29, a9, -a4 });
	int s13 = gmsh::model::geo::addSurfaceFilling({ c13 });

	int c14 = gmsh::model::geo::addCurveLoop({ -a9, a30, a18, -a1 });
	int s14 = gmsh::model::geo::addSurfaceFilling({ c14 });

	int c15 = gmsh::model::geo::addCurveLoop({ -a18, a31, -a15, -a2 });
	int s15 = gmsh::model::geo::addSurfaceFilling({ c15 });

	int c16 = gmsh::model::geo::addCurveLoop({ a15, a32, -a23, -a3 });
	int s16 = gmsh::model::geo::addSurfaceFilling({ c16 });


}


int main(int argc, char** argv) {
	gmsh::initialize();

	gmsh::model::add("Torus");


	build_torus(0, 0, 0, 1, 0.25);
	build_torus(0, 0, -0.25, 1, 0.5);

	std::vector<int> surfaces;
	for (int i = 1; i <= 32; i++) surfaces.push_back(i);

	gmsh::model::geo::addSurfaceLoop(surfaces, 1);
	gmsh::model::geo::addVolume({ 1 });

	gmsh::model::geo::synchronize();

	gmsh::model::mesh::generate(3);

	gmsh::write("Torus.msh");

	//std::set<std::string> args(argv, argv + argc);
	//if (!args.count("-nopopup")) gmsh::fltk::run();

	gmsh::finalize();

	return 0;
}
#include "../../src/graphics/sdl_adapter.h"
#include "./mock_sdl_renderer.h"

class SDLAdapterTest : public ::testing::Test{
  protected:

    SDL *mockSDLRenderer;
    Canvas *canvas;
    TwoDimensionalVector vec1,vec2;
    Circle *cir;
    Rectangle *rect;
    Triangle *tri;

    void SetUp() override{

      mockSDLRenderer = new MockSDLRenderer();
      canvas = new SDLAdapter(1024, 768, mockSDLRenderer);

      vec1=TwoDimensionalVector(Point(5,5),Point(10,5));
      vec2=TwoDimensionalVector(Point(5,5),Point(5,15));

      cir=new Circle(vec1);
      tri=new Triangle(vec1,vec2);
      rect=new Rectangle(vec1,vec2);
    }

    void TearDown() override{
      delete canvas;
      deletePoints(mockSDLRenderer);
      delete mockSDLRenderer;
      delete cir;
      delete tri;
      delete rect;
    }

    static void deletePoints(SDL *mockSDLRenderer){
      if(dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->renderDrawLinesCalledSize()>0)
        delete[] dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->renderDrawLinesCalledPoints();
    }
};

TEST_F(SDLAdapterTest, InitShouldBeCalled) {
  ASSERT_TRUE(dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->isInitCalled());
}


TEST_F(SDLAdapterTest, renderDrawCircleCalledArgsShouldBeCorrect) {
  canvas->drawCircle(cir);
  
  const double *callPoints=dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->renderDrawCircleCalledArgs();

  ASSERT_NEAR(5.0,callPoints[0],0.001);
}

TEST_F(SDLAdapterTest, renderDrawCircleCalledArgsShouldBeCorrect2) {
  canvas->drawCircle(cir);
  
  const double *callPoints=dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->renderDrawCircleCalledArgs();

  ASSERT_NEAR(5.0,callPoints[1],0.001);
}


TEST_F(SDLAdapterTest, renderDrawTriangleCalledArgsShouldBeCorrect) {
  canvas->drawTriangle(tri);

  const double *callPoints=dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->renderDrawLinesCalledPoints();

  ASSERT_NEAR(10.0,callPoints[4],0.001);
}

TEST_F(SDLAdapterTest, renderDrawTriangleCalledArgsShouldBeCorrect2) {
  canvas->drawTriangle(tri);

  const double *callPoints=dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->renderDrawLinesCalledPoints();

  ASSERT_NEAR(5.0,callPoints[5],0.001);
}


TEST_F(SDLAdapterTest, renderDrawRectangleCalledArgsShouldBeCorrect) {
  canvas->drawRectangle(rect);

  const double *callPoints=dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->renderDrawLinesCalledPoints();

  ASSERT_NEAR(10.0,callPoints[4],0.001);
}

TEST_F(SDLAdapterTest, renderDrawRectangleCalledArgsShouldBeCorrect2) {
  canvas->drawRectangle(rect);

  const double *callPoints=dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->renderDrawLinesCalledPoints();

  ASSERT_NEAR(15.0,callPoints[5],0.001);
}


TEST_F(SDLAdapterTest, renderPresentShouldBeCorrect) {
  canvas->display();

  ASSERT_TRUE(dynamic_cast<MockSDLRenderer *>(mockSDLRenderer)->isRenderPresentCalled());
}
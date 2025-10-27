#include <iostream>

class Kruh
{
   private:

      float radius;

   public:

      Kruh()
      {
         radius = 0.0f;
      }

      Kruh( float r )
      {
         setRadius( r );
      }

      void setRadius( float r )
      {
         if ( r < 0.0f )
         {
            radius = 0.0f;
         }
         else
         {
            radius = r;
         }
      }

      float getRadius() const
      {
         return radius;
      }

      float spocitejPlochu() const
      {
         const float pi = 3.14159f;
         return pi * radius * radius;
      }

      float spocitejObvod() const
      {
         const float pi = 3.14159f;
         return 2.0f * pi * radius;
      }

      void vypisUdaje() const
      {
         std::cout << "Polomer kruhu: " << radius << std::endl;
         std::cout << "Plocha kruhu: " << spocitejPlochu() << std::endl;
         std::cout << "Obvod kruhu: " << spocitejObvod() << std::endl;
      }
};

// BONUS: radius kruhu bude sablonovy parametr, a udela pole kruhu a pro kazdy kruh spocita vse

template<int RADIUS>
Kruh vytvorKruh()
{
   Kruh kruh;
   kruh.setRadius( static_cast<float>( RADIUS ) );
   return kruh;
}

int main()
{

   Kruh poleKruhu[] = { vytvorKruh<2>(), vytvorKruh<3>(), vytvorKruh<4>() };

   for ( const Kruh &kruh : poleKruhu )
   {
      kruh.vypisUdaje();
   }


   return 0;
}

#pragma once

void DrawFluffles(Object* fluffles, ObjectManager* manager){
  uint16_t X = fluffles -> X;
  uint16_t Y = fluffles -> Y;
  uint8_t frame = pgm_read_byte_near(pgm_read_byte_near(&(FlufflesFrameRefrence[fluffles->State]))+fluffles->FrameData);
  ard.println(fluffles->State);
  ard.println(frame);
  sprite.drawSelfMasked(X, Y, FlufflesSprite, frame);
}

void DrawTree(Object* obj, ObjectManager* manager){
  uint16_t X = obj -> X;
  uint16_t Y = obj -> Y;

  sprite.drawSelfMasked(X-40,Y,FlufflesSprite,0);
}

void DrawFunction(Object * object, ObjectManager * manager)
{
  switch(object->Type)
  {
    case ObjectType::Fluffles:
      DrawFluffles(object, manager);
      return;
    
    case ObjectType::Tree:
      DrawTree(object, manager);
      return;
  }
}

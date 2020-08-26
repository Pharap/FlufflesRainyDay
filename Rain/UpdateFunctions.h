#pragma once

#include "Object.h"
#include "ObjectManager.h"

void UpdateFluffles(Object* obj, ObjectManager* manager)
{
  if(ard.justPressed(UP_BUTTON))
  {
    if(obj->Y > 0)
      obj->Y -= 18;
  }

  if(ard.justPressed(DOWN_BUTTON))
  {
    if(obj->Y < 36)
      obj->Y += 18;
  }

  if(ard.justPressed(A_BUTTON))
  {
    obj->State = 1;
  }

  if(ard.justPressed(B_BUTTON))
  {
    obj->State = 0;
  }
  
  if(manager->UpdateFrameCount())
  {
    obj->FrameData++;
    obj->FrameData %= 4;
  }
}

void UpdateTree(Object* obj, ObjectManager* manager)
{
    obj->X--;

    if(obj->X < 20)
    {
      obj->Active = false;
      manager->AddObject({ ObjectType::Tree, 0, 0, 1, 0, 200, 0, true });
    }  
}

void RunFunction(Object * object, ObjectManager * manager)
{
  switch(object->Type)
  {
    case ObjectType::Fluffles:
      UpdateFluffles(object, manager);
      return;
    
    case ObjectType::Tree:
      UpdateTree(object, manager);
      return;
  }
}

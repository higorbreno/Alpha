#ifndef CAMERA_H
#define CAMERA_H

class Camera2D {
private:
	float posX, posY;		// Posições da câmera no mundo

public:
	Camera2D();
	~Camera2D();

	virtual float X() const;	// Retorna posição x da câmera no mundo
	virtual float Y() const;	// Retorna posição y da câmera no mundo

	// Move a câmera para a posição determinada
	virtual void MoveTo(float x, float y);
};

inline float Camera2D::X() const
{ return posX; }

inline float Camera2D::Y() const
{ return posY; }


#endif
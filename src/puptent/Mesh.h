/*
 * Copyright (c) 2013 David Wicks, sansumbrella.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once
#include "puptent/PupTent.h"
#include "pockets/Types.h"

namespace puptent
{
  /**
   Collection of 2d vertices suitable for rendering as a triangle strip.
  */
  typedef std::shared_ptr<class RenderMesh2d> RenderMesh2dRef;
  struct RenderMesh2d : Component<RenderMesh2d>
  {
    RenderMesh2d( int vertex_count=3, int render_layer=0 ):
    render_layer( render_layer )
    {
      vertices.assign( vertex_count, Vertex2d{} );
    }

    std::vector<Vertex2d> vertices;
    int                   render_layer = 0;
    //! Convenience method for making circular shapes
    //! If you aren't dynamically changing the circle, consider using a Sprite
    void setAsCircle( const ci::Vec2f &radius, float start_radians=0, float end_radians=M_PI * 2, size_t segments=0 );
    //! Set the mesh bounds to a box shape
    void setAsBox( const ci::Rectf &bounds );
  };

  struct RenderMesh3d : Component<RenderMesh3d>
  {
  	std::vector<Vertex3d> vertices;
  };
} // puptent::


/*
    pbrt source code is Copyright(c) 1998-2015
                        Matt Pharr, Greg Humphreys, and Wenzel Jakob.

    This file is part of pbrt.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are
    met:

    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
    IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
    TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef PBRT_LIGHTS_SPOT_H
#define PBRT_LIGHTS_SPOT_H
#include "stdafx.h"

// lights/spot.h*
#include "pbrt.h"
#include "light.h"
#include "shape.h"

// SpotLight Declarations
class SpotLight : public Light {
  public:
    // SpotLight Public Methods
    SpotLight(const Transform &LightToWorld, const Medium *m, const Spectrum &,
              Float width, Float fall);
    Spectrum Sample_L(const Interaction &ref, const Point2f &sample,
                      Vector3f *wi, Float *pdf, VisibilityTester *vis) const;
    Float Falloff(const Vector3f &w) const;
    Spectrum Power() const;
    Spectrum Sample_L(const Point2f &sample1, const Point2f &sample2,
                      Float time, Ray *ray, Normal3f *Ns, Float *pdfPos,
                      Float *pdfDir) const;
    Float Pdf(const Interaction &, const Vector3f &) const;
    void Pdf(const Ray &, const Normal3f &, Float *pdfPos, Float *pdfDir) const;

  private:
    // SpotLight Private Data
    const Point3f pLight;
    const Spectrum intensity;
    const Float cosTotalWidth, cosFalloffStart;
};

std::shared_ptr<SpotLight> CreateSpotLight(const Transform &l2w,
                                           const Medium *medium,
                                           const ParamSet &paramSet);

#endif  // PBRT_LIGHTS_SPOT_H

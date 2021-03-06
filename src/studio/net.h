// MIT License

// Copyright (c) 2017 Vadim Grigoruk @nesbox // grigoruk@gmail.com

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "tic80_types.h"

typedef struct Net Net;

typedef struct
{
    enum
    {
        HttpGetProgress,
        HttpGetDone,
        HttpGetError,
    } type;

    union
    {
        struct
        {
            s32 size;
            s32 total;
        } progress;

        struct
        {
            s32 size;
            u8* data;
        } done;

        struct
        {
            s32 code;
        } error;
    };

    void* calldata;
    const char* url;

} HttpGetData;

typedef void(*HttpGetCallback)(const HttpGetData*);

Net* netCreate(const char* host);
void netGet(Net* net, const char* url, HttpGetCallback callback, void* calldata);
void netClose(Net* net);
void netTickStart(Net *net);
void netTickEnd(Net *net);

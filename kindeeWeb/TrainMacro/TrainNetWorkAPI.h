//
//  TrainNetWorkingAPI.h
//  SOHUTrain
//
//  Created by apple on 16/8/26.
//  Copyright © 2016年  Kingno. All rights reserved.
//

#ifndef TrainNetWorkAPI_h
#define TrainNetWorkAPI_h

#import "TrainNetWorkConfiguration.h"
#import "TrainNetWorkAPIEngine.h"

//#if PROJECTMODEDEV == 1
//
//
//#else
//
//#endif




#ifdef DEBUG

#define TrainWelcomeURL   [TrainUserDefault objectForKey:TrainWebHostText]
#define TrainIP  TrainWelcomeURL

//#define TrainWelcomeURL  TrainUser.site // @"https://123.56.137.187:9999"
//#define TrainIP           TrainUser.site

//#define TrainIP    @"https://101.201.48.193"
//#define TrainIP    @"http://10.42.0.72:8080"
//#define TrainIP    @"http://192.168.11.127:8080"
#define TrainUpdateText      @"https://lhrcb.newvane.com.cn"


#else

//#define TrainWelcomeURL   @"http://123.56.137.187:9999"
//#define TrainIP  TrainWelcomeURL

#define TrainWelcomeURL   [TrainUserDefault objectForKey:TrainWebHostText]
#define TrainIP           TrainWelcomeURL
#define TrainUpdateText     @"https://lhrcb.newvane.com.cn"


#endif



#endif /* TrainNetWorkAPI_h */

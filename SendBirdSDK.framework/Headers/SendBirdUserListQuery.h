//
//  SendBirdUserListQuery.h
//  SendBirdSDK
//
//  Created by Jed Kyung on 1/13/16.
//  Copyright © 2016 SENDBIRD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SendBirdClient.h"

@class SendBirdClient;

@interface SendBirdUserListQuery : NSObject

- (id) initWithSendBirdClient:(SendBirdClient *)sendBirdClient;

- (BOOL) isLoading;

/**
 *  Set the number of users per page (limit)
 *
 *  @param lmt Number of users per page
 */
- (void) setLimit:(int) lmt;

/**
 *  Stop retrieving the user list
 */
- (void) cancel;

/**
 *  Check if there is more users to retrieve
 *
 *  @return Returns YES if there is a next page, otherwise returns NO
 */
- (BOOL) hasNext;

/**
 *  Get the list of users
 *
 *  @param onResult Callback invoked upon success. queryResult is an array of [`SendBirdAppUser`](./SendBirdAppUser.html)
 *  @param onError  Callback invoked upon error
 */
- (void) nextWithResultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSInteger code))onError;

@end

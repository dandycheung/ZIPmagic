// $Id: FileDeleteDispatcher.h,v 1.2.2.1 2001/07/05 23:32:35 serge Exp $
//
// Copyright (c)1998-2001 Aladdin Systems, Inc. All Rights Reserved.
// 245 Westridge Drive, Watsonville, CA 95076, USA
// http://www.aladdinsys.com/
// 1-831-761-6200
//
// This source code and specific concepts contained herein are confidential
// information and property of Aladdin Systems. Distribution is prohibited
// without written permission of Aladdin Systems.

#if !defined stuffit5_event_FileDeleteDispatcher_h_included
#define stuffit5_event_FileDeleteDispatcher_h_included

#include "un/warnings.h"
#include <list>
#include "stuffit5/event/FileDeleteListener.h"

/** This class generates event notifications for <code>FileDeleteEvent</code>.
It maintains a list of <code>FileDeleteListener</code>s.

<p>The implementation of this class makes a copy of the listener list when
firing events. This allows listeners to be safely added and removed during
event handling but it may lead to performance problems in environments
where events are used frequently.

@author serge@aladdinsys.com
@version $Revision: 1.2.2.1 $, $Date: 2001/07/05 23:32:35 $
*/

namespace stuffit5 {
    namespace event {
        class FileDeleteDispatcher {
        public:
            /** Register an <code>FileDeleteListener</code> to be periodically notified.
            @param l an <code>FileDeleteListener</code> to be added to the notification list
            */
            void addFileDeleteListener(stuffit5::event::FileDeleteListener* l) {
                fileDeleteListeners.push_back(l);
            }

            /** Remove an <code>FileDeleteListener</code> from the list of listeners.
            @param l an <code>FileDeleteListener</code> to be removed from the notification list
            */
            void removeFileDeleteListener(stuffit5::event::FileDeleteListener* l) {
                fileDeleteListeners.remove(l);
            }

            /** Send an <code>FileDeleteEvent</code> to all registered listeners.
            @param e an <code>FileDeleteEvent</code> to be dispatched
            */
            bool fireFileDeleteEvent() {
                bool result = true;
                std::list<stuffit5::event::FileDeleteListener*> al = fileDeleteListeners;
                for (std::list<stuffit5::event::FileDeleteListener*>::iterator i = al.begin(); i != al.end(); i++)
                    result = result && (*i)->fileDeleteEvent();
                return result;
            }

        protected:
            /** A list of registered <code>FileDeleteListener</code>s. */
            std::list<stuffit5::event::FileDeleteListener*> fileDeleteListeners;
        };
    }
}

#endif

